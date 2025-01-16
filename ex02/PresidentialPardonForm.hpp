#include "AForm.hpp"
#include <iostream>
#include <fstream>

class PresidentialPardonForm : public Form {
	private:
		std::string target;
	
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

		void	execute_action() const override;
};
