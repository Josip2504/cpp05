#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45), target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: Form("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: Form(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		Form::operator=(other);
		target = other.target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::execute_action() const {

	std::cout << "Makes some drilling noises" << std::endl;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::bernoulli_distribution dist(0.5);

	if (dist(gen)) {
		std::cout << target << " has been robotomized" << std::endl;
	} else {
		std::cout << target << " robotomy failed" << std::endl;
	}
}
