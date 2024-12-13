#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main() {
	std::cout << GREEN << "Can sign" << WHITE <<  std::endl;
	try {
		Bureacrat ivan("Ivan", 3);
		std::cout << ivan << std::endl;

		Form form1("Form1", 3, 5);
		std::cout << form1 << std::endl;

		ivan.signForm(form1);
		std::cout << form1 << std::endl;

	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << GREEN << "Throw exception then increment grade" << WHITE <<  std::endl;
	try {
		Bureacrat marko("Marko", 150);
		std::cout << marko << std::endl;

		Form form2("Form2", 149, 149);
		std::cout << form2 << std::endl;

		marko.signForm(form2);
		std::cout << form2 << std::endl;

		marko.incrementGrade(); // increment grade to 149 so it can be signed

		marko.signForm(form2);
		std::cout << form2 << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << RED << "Form 0" << WHITE <<  std::endl;
	try {
		Form form3("Form3", 0, 0);
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << RED << "Form 151" << WHITE <<  std::endl;
	try {
		Form form4("Form4", 151, 151);
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
