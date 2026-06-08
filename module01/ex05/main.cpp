#include "Harl.hpp"

int main() {
    Harl harl;

    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");
    harl.complain("UNKNOWN"); // made up level, checks that complain() does nothing when the level isn't recognized
    /*
    harl.complain("WARNING");
    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("NONSENSE");
    harl.complain("ERROR");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("DEBUG");
    harl.complain("DEBUG");
    harl.complain("ERROR");
    harl.complain("ERROR");
    harl.complain("ERROR");
    harl.complain("WARNING");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("DEBUG");
     */
    return 0;
}
