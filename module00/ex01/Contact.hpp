#ifndef CONTACT_HPP
#define CONTACT_HPP

// string is comfier than using char *, it auto manages memory
#include <string>

// a class is a blueprint that has objects, here i hav strings
// and the methods to set/get them.
// setters: take a value and put in the private field
// getters: retrieve what's stored
// public and private are for access control
// private: only code inside the class can touch it
// public: anyone can use it, setters and getters are public
// bc they are like a controlled door to the private data
// the Pattern™ is encapsulation, hide the data (private)
// and expose controlled access (public methods)
class Contact {
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;

    public:
        Contact();
        void set_first_name(std::string name);
        void set_last_name(std::string name);
        void set_nickname(std::string nick);
        void set_phone_number(std::string number);
        void set_darkest_secret(std::string secret);

        std::string get_first_name() const;
        std::string get_last_name() const;
        std::string get_nickname() const;
        std::string get_phone_number() const;
        std::string get_darkest_secret() const;

        bool is_empty() const;
};

#endif
