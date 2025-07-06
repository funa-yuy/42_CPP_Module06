#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

// ------------------------------------------------
// include
// ------------------------------------------------

#include <iostream>
#include <string>
#include <stdint.h>
#include"Data.hpp"

// ------------------------------------------------
// class
// ------------------------------------------------

class Serializer {
	public:
		Serializer();
		Serializer(const std::string& name, int grade);
		Serializer& operator=(const Serializer& copy);
		Serializer(const Serializer& copy);
		~Serializer();

		static	uintptr_t serialize(Data* ptr);
		static	Data* deserialize(uintptr_t raw);
	private:
};

// ------------------------------------------------
// function
// ------------------------------------------------

#endif
