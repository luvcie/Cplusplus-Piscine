#include "PhoneBook.hpp"
#include <iostream>
#include <string> // gives std::getline, it reads one whole line of input and stores in a std::string
#include <sstream> // gives string streams (std::istringstream)

// keep asking for one field until the user types something that isn't empty
// (subject says a saved contact can't have empty fields)
// returns false on ctrl-D so can get out of the add
static bool prompt_field(const std::string &label, std::string &out) {
    while (true) {
        std::cout << label;
        if (!std::getline(std::cin, out))
            return false;
        if (!out.empty())
            return true;
        std::cout << "Field can't be empty, try again." << std::endl;
    }
}

// fill every field one at a time, abort the whole add if any read hits EOF
static bool create_contact(Contact &contact) {
    std::string input;

    if (!prompt_field("Enter first name: ", input))
        return false;
    contact.set_first_name(input);

    if (!prompt_field("Enter last name: ", input))
        return false;
    contact.set_last_name(input);

    if (!prompt_field("Enter nickname: ", input))
        return false;
    contact.set_nickname(input);

    if (!prompt_field("Enter phone number: ", input))
        return false;
    contact.set_phone_number(input);

    if (!prompt_field("Enter darkest secret: ", input))
        return false;
    contact.set_darkest_secret(input);

    return true;
}

static void handle_add(PhoneBook &phonebook) {
    Contact new_contact;
    if (!create_contact(new_contact)) // ctrl-D mid-add, don't save a half contact
        return;
    phonebook.add_contact(new_contact);
    std::cout << "Contact added succesfully." << std::endl;
}

static void handle_search(const PhoneBook &phonebook) {
    if (!phonebook.search_contacts()) // empty phone book so dont ask for index
        return;

    std::cout << "Enter index to display: ";
    std::string input;
    std::getline(std::cin, input); // getline gives us text but display_contact wants int
    std::istringstream iss(input);
    int index;                     // so isstringstream reads the int back out
    if (!(iss >> index)) {         // if typed letters or nothing then error and gtfo
        std::cout << "Invalid Index." << std::endl;
        return;
    }
    phonebook.display_contact(index);
}

int main() {
    PhoneBook phonebook; // creates phonebook object that stores data
    std::string command;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command)) // ctrl-D / EOF, stop or we loop forever
            break;

        if (command == "ADD") {
            handle_add(phonebook);
        } else if (command == "SEARCH") {
            handle_search(phonebook);
        } else if (command == "EXIT") {
            break;
        }
    }
    return 0;
}
