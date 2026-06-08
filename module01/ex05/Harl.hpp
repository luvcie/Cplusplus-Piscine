#ifndef HARL_HPP
#define HARL_HPP

# include <string>

class Harl {
    private:
        // the 4 messages, private, only complain picks which to call
        void debug();
        void info();
        void warning();
        void error();
    public:
        void complain(std::string level);
};

#endif
