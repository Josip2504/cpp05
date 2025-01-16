#include "Intern.hpp"

int main() {
    Intern someRandomIntern;
    Form* rrf;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf) {
        std::cout << *rrf << std::endl;
        delete rrf;  // Don't forget to delete it!
    }

    return 0;
}
