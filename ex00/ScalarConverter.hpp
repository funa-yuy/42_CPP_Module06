#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

// ------------------------------------------------
// include
// ------------------------------------------------

#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include <iomanip>
#include <stdlib.h>
#include <math.h>
#include <cerrno>

// ------------------------------------------------
// class
// ------------------------------------------------

class ScalarConverter {
	public:
		ScalarConverter();
		ScalarConverter(const std::string& name, int grade);
		ScalarConverter& operator=(const ScalarConverter& copy);
		ScalarConverter(const ScalarConverter& copy);
		~ScalarConverter();

		static void	convert(const std::string& str);

	private:
};

// ------------------------------------------------
// function
// ------------------------------------------------

#endif
