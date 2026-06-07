#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
    private:
        Contact contacts[8];
        int contact_count;
        int oldest_index;

    //operations on the private contacts
    public:
        PhoneBook();

        void add_contact(Contact new_contact);
        bool search_contacts() const;
        void display_contact(int index) const;
}; // always end class with semicolon

#endif
