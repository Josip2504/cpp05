#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Intern created." << std::endl;
}

Intern::Intern(const Intern&) {
    std::cout << "Intern copied." << std::endl;
}

Intern& Intern::operator=(const Intern&) {
    std::cout << "Intern assigned." << std::endl;
    return *this;
}

Intern::~Intern() {
    std::cout << "Intern destroyed." << std::endl;
}

Form* Intern::makeForm(const std::string& formName, const std::string& target) const {
    std::string formTypes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    Form* forms[3] = {
        new ShrubberyCreationForm(target),
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target)
    };

    for (int i = 0; i < 3; i++) {
        if (formName == formTypes[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            for (int j = 0; j < 3; j++) {
                if (i != j) delete forms[j];  // Delete unused forms
            }
            return forms[i];
        }
    }

    std::cout << "Error: Form '" << formName << "' not found!" << std::endl;
    for (int i = 0; i < 3; i++) {
        delete forms[i];  // Clean up all forms
    }
    return nullptr;
}
