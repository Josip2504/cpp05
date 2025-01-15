#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        Bureacrat bob("Bob", 130);  // Bureaucrat with grade 130
        ShrubberyCreationForm shrubberyForm("home");

        std::cout << shrubberyForm << std::endl;

        // Sign the form
        bob.signForm(shrubberyForm);
        std::cout << shrubberyForm << std::endl;

        // Execute the form
        bob.executeForm(shrubberyForm);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}