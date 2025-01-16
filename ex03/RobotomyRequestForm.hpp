#include "AForm.hpp"
#include <iostream>
#include <random>
#include <string>

class RobotomyRequestForm : public Form {
	private:
		std::string target;
	
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		void	execute_action() const override;
};
