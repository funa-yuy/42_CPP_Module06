#ifndef BASE_HPP
# define BASE_HPP

// ------------------------------------------------
// include
// ------------------------------------------------

#include <iostream>
#include <string>
#include <stdlib.h>

// ------------------------------------------------
// class
// ------------------------------------------------

class Base {
	public:
		virtual ~Base();
};

// ------------------------------------------------
// function
// ------------------------------------------------

Base*	generate(void);
void	identify(Base *p);
void	identify(Base &p);

#endif
