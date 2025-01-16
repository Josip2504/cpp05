#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	std::cout << YELLOW <<  "Shrubbery test" << WHITE << std::endl << std::endl;
	try {
		Bureacrat bob("Bob", 130);  // Bureaucrat with grade 130
		ShrubberyCreationForm shrubberyForm("home");

		std::cout << shrubberyForm << std::endl << std::endl;

		// Sign the form
		bob.signForm(shrubberyForm);
		std::cout << std::endl << shrubberyForm << std::endl << std::endl;

		// Execute the form
		bob.executeForm(shrubberyForm);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << YELLOW << "Presidental pardon test" <<  WHITE << std::endl;
	try {
		Bureacrat tom("Tom", 5);  // Bureaucrat with grade 5
		PresidentialPardonForm presidentalForm("President");

		std::cout << presidentalForm << std::endl << std::endl;

		// Sign the form
		tom.signForm(presidentalForm);
		std::cout << std::endl << presidentalForm << std::endl << std::endl;

		// Execute the form
		tom.executeForm(presidentalForm);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}