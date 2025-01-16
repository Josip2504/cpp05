#include "AForm.hpp"

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
	: name(name), signedStatus(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
		checkGrade(gradeToSign);
		checkGrade(gradeToExecute);
	}

Form::Form(const Form& other) : name(other.name), signedStatus(other.signedStatus), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		signedStatus = other.signedStatus;
	}
	return *this;
}

Form::~Form() {}

const std::string&	Form::getName() const {
	return name;
}

bool	Form::isSigned() const {
	return signedStatus;
}

int	Form::getGrateToSign() const {
	return gradeToSign;
}

int	Form::getGrateToExecute() const {
	return gradeToExecute;
}

void	Form::beSigned(const Bureacrat& bureacrat) {
	if (bureacrat.getGrade() > gradeToSign) {
		throw GradeTooHighException();
	}
	signedStatus = true;
}

void	Form::execute(const Bureacrat& executor) const {
	if (!isSigned()) {
		throw NotSignedException();
	}
	if (executor.getGrade() > gradeToExecute) {
		throw GradeTooLowException();
	}
	execute_action();
}

const char*	Form::GradeTooHighException::what() const noexcept {
	return "Grade of Form is too hight";
}

const char*	Form::GradeTooLowException::what() const noexcept {
	return "Grade of Form is too low";
}

const char* Form::NotSignedException::what() const noexcept {
	return "Form is not signed";
}

void	Form::checkGrade(int grade) const {
	if (grade < 1) {
		throw GradeTooHighException();
	}
	if (grade > 150) {
		throw GradeTooLowException();
	}
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << "Form " << form.getName() << ", signed: " << (form.isSigned() ? GREEN : RED) << (form.isSigned() ? "yes" : "no")
	<< WHITE << ", grade required to sign: " << form.getGrateToSign() << ", grade required to execute: "
	<< form.getGrateToExecute();
	return os;
}
