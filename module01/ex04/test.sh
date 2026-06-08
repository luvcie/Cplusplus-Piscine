#!/usr/bin/env bash
# allowed per the c++ module 01 subject, general rules, page 4:
# "You can add some additional files if you need to... As these assignments are
#  not verified by a program, feel free to do so as long as you turn in the
#  mandatory files."

make -s re >/dev/null 2>&1

pass=0
fail=0
tmp=$(mktemp -d)

# label, file content, s1, s2, expected output
content() {
    printf '%s' "$2" > "$tmp/in"
    ./replace "$tmp/in" "$3" "$4" >/dev/null 2>&1
    got=$(cat "$tmp/in.replace" 2>/dev/null)
    if [ "$got" = "$5" ]; then
        echo "[ok]   $1"
        pass=$((pass + 1))
    else
        echo "[FAIL] $1 (got '$got')"
        fail=$((fail + 1))
    fi
    rm -f "$tmp/in" "$tmp/in.replace"
}

# label, then args, should exit non-zero
err() {
    label="$1"; shift
    ./replace "$@" >/dev/null 2>&1
    if [ $? -ne 0 ]; then
        echo "[ok]   $label"
        pass=$((pass + 1))
    else
        echo "[FAIL] $label"
        fail=$((fail + 1))
    fi
}

echo "content"
content "basic"               "hello world" "hello" "HI" "HI world"
content "multiple"            "aaa aaa aaa" "aaa"   "X"  "X X X"
content "not found stays"     "nothing"     "zzz"   "X"  "nothing"
content "empty s2 deletes"    "XhelloX"     "X"     ""   "hello"
content "s2 contains s1"      "banana"      "a"     "aa" "baanaanaa"
content "no trailing newline" "noeol"       "o"     "0"  "n0e0l"
content "empty file"          ""            "a"     "b"  ""

echo "errors"
err "no args"
err "missing s2"        "$tmp/x"
err "too many"          "$tmp/x" a b c
err "no such file"      "/tmp/nope_42" a b
err "empty s1"          "$tmp/x" "" b

rm -rf "$tmp"
make -s fclean >/dev/null 2>&1

echo
echo "passed $pass failed $fail"
