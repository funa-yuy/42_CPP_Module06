#include"Base.hpp"

// ```bash
// valgrind --leak-check=full ./Identify
// ```
int	main()
{
	Base* p = generate();
	identify(p);
	identify(*p);

	std::cout << std::endl;

	Base* base = new Base;
	identify(base);
	identify(*base);

	delete p;
	delete base;
	return (0);
}
