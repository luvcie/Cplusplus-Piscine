#include "Contact.hpp"
#include <string>

// this is the constructor, a method that runs automatically
// when a Contact is created
// name = class name, and no return type
Contact::Contact() {
}

void Contact::set_first_name(std::string name){
    first_name = name;
}

void Contact::set_last_name(std::string name) {
    last_name = name;
}

void Contact::set_nickname(std::string nick) {
    nickname = nick;
}

void Contact::set_phone_number(std::string number) {
    phone_number = number;
}

void Contact::set_darkest_secret(std::string secret){
    darkest_secret = secret;
}

// const because we want it read-only
std::string Contact::get_first_name() const {
    return first_name;
}

std::string Contact::get_last_name() const {
    return last_name;
}

std::string Contact::get_nickname() const {
    return nickname;
}

std::string Contact::get_phone_number() const {
    return phone_number;
}

std::string Contact::get_darkest_secret() const {
    return darkest_secret;
}

// .empty returns true if string is empty bc slot was not filled
// test first_name because a real contact always has one
// blank first name = empty slot.
bool Contact::is_empty() const {
    return first_name.empty();
}
