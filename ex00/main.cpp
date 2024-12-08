#include "Bureaucrat.hpp"
#include <iostream>

int	main() {
	std::cout << "\033[32m" << "Increment test" << "\033[0m" <<  std::endl;
	try {
		Bureacrat ivan("Ivan", 2);
		std::cout << ivan << std::endl;

		ivan.incrementGrade();
		std::cout << ivan << std::endl;

		ivan.incrementGrade(); // this throw exception cuz grade is lower than 1
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "\033[32m" << "Decrement test" << "\033[0m" <<  std::endl;
	try {
		Bureacrat marko("Marko", 149);
		std::cout << marko << std::endl;

		marko.decrementGrade();
		std::cout << marko << std::endl;

		marko.decrementGrade(); // this throw exception cuz grade is higher than 150
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\033[32m" << "0 test" << "\033[0m" <<  std::endl;
	try {
		Bureacrat josip("Josip", 0);
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "\033[32m" << "151 test" << "\033[0m" <<  std::endl;
	try {
		Bureacrat goran("Goran", 151);
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
