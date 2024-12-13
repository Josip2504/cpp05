#ifndef BUREACRAT
#define BUREACRAT

#include <iostream>
#include <string>
#include <stdexcept>

class Form;

class Bureacrat {
	private:
		const	std::string name;
		int		grade;
		void	checkGrade(int grade) const;

	public:
		Bureacrat(const std::string& name, int grade);
		Bureacrat(const Bureacrat& other);
		Bureacrat& operator=(const Bureacrat& other);
		~Bureacrat();

		const	std::string& getName() const;
		int		getGrade() const;

		void	incrementGrade();
		void	decrementGrade();
		void	signForm(Form& form);

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const noexcept override;
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const noexcept override;
		};
};

std::ostream& operator<<(std::ostream& os, const Bureacrat& b);

#endif