#include"Serializer.hpp"

int main()
{
	Data* ptr = new Data;

	ptr->str = "Tokyo";
	ptr->num = 42;

	std::cout << "--- 元のData* ptr ---" << std::endl << ptr << std::endl;
	std::cout << std::endl;

	uintptr_t res = Serializer::serialize(ptr);
	std::cout << "--- Data* ptr → uintptr_t resにキャスト ---" << std::endl << res << std::endl;
	std::cout << std::endl;


	Data* ptr2 = Serializer::deserialize(res);
	std::cout << "--- uintptr_t res → Data* ptr2にキャスト ---" << std::endl << ptr2 << std::endl;
	std::cout << std::endl;

	uintptr_t res2 = Serializer::serialize(ptr2);
	std::cout << "--- Data* ptr2 → uintptr_t res2にキャスト ---" << std::endl << res2 << std::endl;
	std::cout << std::endl;


	std::cout << std::endl;
	std::cout << "Data*: キャスト前とキャスト後のアドレスが"
			  << (ptr == ptr2 ? "\x1b[32m値が同じ" : "\x1b[31m値が異なる") << "\x1b[39m" << std::endl;
	std::cout << "num: " << ptr->num << " str: " << ptr->str << std::endl;
	std::cout << "num: " << ptr2->num << " str: " << ptr2->str << std::endl;

	std::cout << std::endl;
	std::cout << "uintptr_t: キャスト前とキャスト後のアドレスが"
			  << (ptr == ptr2 ? "\x1b[32m値が同じ" : "\x1b[31m値が異なる") << "\x1b[39m" << std::endl;

	delete ptr;
	return 0;
}
