#include <iostream> // cerr, cout, .rdbuff, etc
#include <fstream> // ifstream / ofstream, c++ way to read write/files
#include <sstream> // stringstream, to dump entire file into a string
#include <string> // .find (searches for a substring inside a string)

int main(int argc, char** argv) {
    // needs exactly 3 arguments after program name: filename, s1, s2
    if (argc != 4) {
        std::cerr << "usage: ./replace <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    // find("") would create an infinite loop
    if (s1.empty()) {
        std::cerr << "error: s1 can't be empty" << std::endl;
        return 1;
    }

    // open input file, c_str() bc in c++98 stream ctor wants  a const char*
    std::ifstream in(filename.c_str());
    if (!in.is_open()) {
        std::cerr << "error: can't open " << filename << std::endl;
        return 1;
    }

    // read whole file into one string
    std::stringstream buffer;
    buffer << in.rdbuf(); // rdbuf dumps file buffer into stream
    std::string content = buffer.str();
    in.close();

    // build result replacing manually every s1 with s2 using find + substr
    // (std::string::replace is forbidde u.u)
    std::string result;
    size_t pos = 0;
    size_t found;
    while ((found = content.find(s1, pos)) != std::string::npos) {
        result += content.substr(pos, found - pos); // text before match
        result += s2;                               // replacement
        pos = found + s1.length();            // go past matched s1
    }
    result += content.substr(pos); // what is left after last match

    // write result to <filename>.replace
    std::ofstream out((filename + ".replace").c_str());
    if (!out.is_open()) {
        std::cerr << "error: can't create " << filename << ".replace" << std::endl;
        return 1;
    }
    out << result;
    out.close();

    return 0;
}

// flow:
// check there are 3 args (filename, s1, s2), refuse empty s1
// open the file, read the whole thing into one string with rdbuf
// walk the string: find each s1, copy the text before it, drop in s2, jump past s1
// glue on whatever is left after the last match
// write the rebuilt string to <filename>.replace

// replacing hello -> HI in "hello world":
// find "hello" at 0, copy the bit before (nothing), add "HI", jump to pos 5
// find "hello" from pos 5 -> not found, stop
// the loop never copied " world", so the last line glues it on -> "HI world"
// the original file is left alone, the result goes into a new file next to it
// called <filename>.replace (so input.txt -> input.txt.replace)
