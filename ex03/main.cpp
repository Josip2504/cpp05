#include "Intern.hpp"

int main() {
	Intern someRandomIntern;
	Form* form;
	Bureacrat tom("Tom", 45);
	std::cout << YELLOW << "-------Working test-------" << WHITE << std::endl << std::endl;

	form = someRandomIntern.makeForm("robotomy request", "Robo");
	if (form)
	{
		std::cout << *form << std::endl << std::endl;

		tom.signForm(*form);
		std::cout << *form << std::endl << std::endl;

		tom.executeForm(*form);
		
		std::cout << std::endl;
	} else {
		std::cerr << "Failed to create form" << std::endl;
	}

	std::cout << YELLOW << "-------Fail test-------" << WHITE << std::endl << std::endl;

	form = someRandomIntern.makeForm("invalid name", "fail");
	if (form)
		std::cout << *form << std::endl;
	else
		std::cerr << "Failed to create form" << std::endl;

	std::cout << std::endl;

	return 0;
}
