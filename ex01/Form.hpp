#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define WHITE "\033[0m"

class Form {
	private:
		const std::string	name;
		bool				signedStatus;
		const int			gradeToSign;
		const int			gradeToExecute;
		void				checkGrade(int grade) const;
	public:
		Form(const std::string& name, int gradeToSign, int gradeToExecute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		const std::string&	getName() const;
		bool				isSigned() const;
		int					getGrateToSign() const;
		int					getGrateToExecute() const;
		void				beSigned(const Bureacrat& bureacrat);

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const noexcept override;
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const noexcept override;
		};
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif