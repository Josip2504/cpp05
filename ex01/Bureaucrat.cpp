#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureacrat::Bureacrat(const std::string& name, int grade) : name(name), grade(grade) {
	checkGrade(grade);
}

Bureacrat::Bureacrat(const Bureacrat& other) : name(other.name), grade(other.grade) {}

Bureacrat& Bureacrat::operator=(const Bureacrat& other) {
	if (this != &other) {
		grade = other.grade;
	}
	return *this;
}

Bureacrat::~Bureacrat() {}

const	std::string& Bureacrat::getName() const {
	return name;
}

int	Bureacrat::getGrade() const {
	return grade;
}

void	Bureacrat::incrementGrade() {
	checkGrade(grade - 1);
	--grade;
}

void	Bureacrat::decrementGrade() {
	checkGrade(grade + 1);
	++grade;
}

const char*	Bureacrat::GradeTooHighException::what() const noexcept {
	return "Grade is too hight!";
}

const char*	Bureacrat::GradeTooLowException::what() const noexcept {
	return "Grade is too low!";
}

void	Bureacrat::checkGrade(int grade) const {
	if (grade < 1) {
		throw GradeTooHighException();
	}
	if (grade > 150) {
		throw GradeTooLowException();
	}
}

std::ostream& operator<<(std::ostream& os, const Bureacrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}

void	Bureacrat::signForm(Form& form) {
	try {
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << name << " could not sing " << form.getName() << " because " << e.what()
		<< " for " << name << std::endl;
	}
}
