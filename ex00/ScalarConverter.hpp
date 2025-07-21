#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

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
		static void	convert(const std::string& str);

	private:
		ScalarConverter();
		ScalarConverter(const std::string& name, int grade);
		ScalarConverter& operator=(const ScalarConverter& copy);
		ScalarConverter(const ScalarConverter& copy);
		~ScalarConverter();
};

// ------------------------------------------------
// function
// ------------------------------------------------

#endif
