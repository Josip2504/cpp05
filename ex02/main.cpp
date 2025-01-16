#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	Bureacrat bob("Bob", 130);
	Bureacrat tom("Tom", 45);
	Bureacrat john("John", 5);

	ShrubberyCreationForm shrubberyForm("home");
	PresidentialPardonForm presidentalForm("President");
	RobotomyRequestForm robotomyForm("Robot");

	std::cout << YELLOW <<  "Unsigned forms" << WHITE << std::endl;
	std::cout << shrubberyForm << std::endl;
	std::cout << robotomyForm << std::endl;
	std::cout << presidentalForm << std::endl << std::endl;

	try {
		std::cout << YELLOW <<  "Shrubbery test" << WHITE << std::endl;
		bob.signForm(shrubberyForm);
		std::cout << shrubberyForm << std::endl << std::endl;
		bob.executeForm(shrubberyForm);

		std::cout << std::endl << YELLOW << "Robotomy request test" <<  WHITE << std::endl;
		bob.signForm(robotomyForm);
		std::cout << robotomyForm << std::endl << std::endl;
		tom.signForm(robotomyForm);
		std::cout << robotomyForm << std::endl << std::endl;
		tom.executeForm(robotomyForm);

		std::cout << std::endl << YELLOW << "Presidental pardon test" <<  WHITE << std::endl;
		john.signForm(presidentalForm);
		std::cout << presidentalForm << std::endl << std::endl;
		john.executeForm(presidentalForm);

	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
