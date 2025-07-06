#include"Base.hpp"
#include"A.hpp"
#include"B.hpp"
#include"C.hpp"


Base::~Base() {};

// ↑↑↑ Orthodox Canonical Form --------------------------------------

//A、B、Cのいずれかをランダムにインスタンス化し、そのインスタンスをBaseポインタとして返す
Base* generate(void) {
	Base	*p;
	int		i;

	srand(clock());
	i = rand();
	if (i % 3 == 0)
		p = new A;
	else if(i % 3 == 1)
		p = new B;
	else
		p = new C;
	return (p);
}

//p が指すオブジェクトの実際の型 (”A”、”B”、または”C”) を出力します。
void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "invalid Class" << std::endl;
}

class D : public Base{
};

//p が参照するオブジェクトの実際の型(”A”、”B”、または”C”) を出力します。この関数内でポインタを使用することは禁止されています。
void identify(Base& p) {

	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	} catch(const std::exception& e) {
		try {
			B& b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "B" << std::endl;
		} catch(const std::exception& e) {
			try {
				C& c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "C" << std::endl;
			} catch(const std::exception& e) {
				std::cout << "Error: " << e.what() << std::endl;
			}
		}
	}
}
