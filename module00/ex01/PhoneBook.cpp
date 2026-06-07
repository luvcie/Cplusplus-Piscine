#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip> // i/o manipulators, to format what cout prints
// setw sets width to line up columns/have padding

/// initialize contacts and index to 0
PhoneBook::PhoneBook() : contact_count(0), oldest_index(0) {
}

void PhoneBook::add_contact(Contact new_contact) {
    contacts[oldest_index] = new_contact; // store contact
    // and move written position forwards, wrapping to 0 after 7
    // 0->1->2->3->4->5->6->7->0->1->... index 7 + 1 = 8, 8 % 8 = 0, so it wraps to start
    oldest_index = (oldest_index + 1) % 8;
    if (contact_count < 8)
        ++contact_count;
}

// takes: string
// returns: a string (a copy). static = this helper stays private to this file
static std::string fit_column(std::string str) {
    if (str.length() > 10) // if it's too long for the column (.length comes from std::string and is like strlen)
        return str.substr(0,9) + "."; // then return the first 9 chars + dot = 10
    return str; // if it fits shrimply return unchanged
}

bool PhoneBook::search_contacts() const {
    if (contact_count == 0) {
        std::cout << "No contacts in phonebook." << std::endl;
        return false;
    }

// i create table
// Index | First Name| Last Name | Nickname
std::cout << std::setw(10) << "Index" << "|";
std::cout << std::setw(10) << "First Name" << "|";
std::cout << std::setw(10) << "Last Name" << "|";
std::cout << std::setw(10) << "Nickname" << std::endl;
// starting to get tired of this annoying namespaces syntax i'm forced to use btw

// walk through every filled contact one per row
// i < contact_count stops at the count of real contact (as many as are currently added)
// each iteration prints oneline and setw(10) pads every cell of the table to exactly 10 chars
// so everything inside the table will fit nicely even if it's too long for it
for (int i = 0; i < contact_count; i++) {
    std::cout << std::setw(10) << i << "|";
    std::cout << std::setw(10) << fit_column(contacts[i].get_first_name()) << "|";
    std::cout << std::setw(10) << fit_column(contacts[i].get_last_name()) << "|";
    std::cout << std::setw(10) << fit_column(contacts[i].get_nickname()) << std::endl;
    }
    return true;
}

// guard clause that checks the bounds of the index before touching the array
// if user asks for contact that doesn't exist prints an error
void PhoneBook::display_contact(int index) const {
    if (index < 0 || index >= contact_count) {
        std::cout << "Invalid Index." << std::endl;
        return;
    }

    // print all fields, table cuts everything to 10 chars so here show picked contact full
    std::cout << "First Name: " << contacts[index].get_first_name() << std::endl;
    std::cout << "Last Name: " << contacts[index].get_last_name() << std::endl;
	std::cout << "Nickname: " << contacts[index].get_nickname() << std::endl;
	std::cout << "Phone Number: " << contacts[index].get_phone_number() << std::endl;
	std::cout << "Darkest Secret: " << contacts[index].get_darkest_secret() << std::endl;

}

// flow:
// user types SEARCH, search_contacts() runs
// header gets printed once before loop
// then for loop makes one row per contact and fits
// then program asks for an index
// user types for example 1 and display_contact(1) runs, guard checks its valid
// and then prints the full thing first name lasat name nickname number secret...
