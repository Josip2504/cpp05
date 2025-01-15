#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: Form("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: Form(other), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		Form::operator=(other);
		target = other.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::execute_action() const {
	std::ofstream file(target + "_shrubbery");
	if (!file.is_open()) {
		throw std::ios_base::failure("Failed to create file");
	}
	file << "       _-_"
			"    /~~   ~~\""
			" /~~         ~~\""
			"{               }"
			" \"  _-     -_  /"
			"   ~  \\ //  ~"
			"_- -   | | _- _"
			"  _ -  | |   -_"
			"      // \\";
	file.close();
	std::cout << "Shrubbery has been created at " << target << "_shrubbery" << std::endl;
}