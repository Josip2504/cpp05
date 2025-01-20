#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern creted" << std::endl;
}

Intern::Intern(const Intern&) {
	std::cout << "Intern copied" << std::endl;
}

Intern& Intern::operator=(const Intern&) {
	std::cout << "Intern assigned" << std::endl;
	return *this;
}

Intern::~Intern() {
	std::cout << "Intern destroyed" << std::endl;
}

Form *createPresidentialPardonForm(std::string const &name) {
	return new PresidentialPardonForm(name);
}

Form *createRobotomyRequestForm(std::string const &name) {
	return new RobotomyRequestForm(name);
}

Form *createShrubberyCreationForm(std::string const &name) {
	return new ShrubberyCreationForm(name);
}

Form *Intern::makeForm(const std::string& formName, const std::string& target) const {
	Form *(*x[3])(std::string const &) = {
		createShrubberyCreationForm,
		createRobotomyRequestForm,
		createPresidentialPardonForm
	};

	std::string validNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidental pardon"
	};

	for (int i = 0; i < 3; i++) {
		if (validNames[i] == formName) {
			std::cout << "Intern creates " << formName << std::endl;
			return x[i](target);
		}
	}

	std::cerr << "Error: Invalid form name" << std::endl;
	return nullptr;
}
