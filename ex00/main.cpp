#include"ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc == 2)
		ScalarConverter::convert(argv[1]);
	return 0;
}

// struct TestCase {
// 	const char* value;
// 	const char* text;
// };

// #include <float.h>
// int main(void)
// {
// 	TestCase test[] = {
// 		{"a", "char"},
// 		{"Z", "char"},
// 		{"!", "char"},
// 		{"0", "int"},
// 		{"42", "int"},
// 		{"-42", "int"},
// 		{"4.2f", "float"},
// 		{"-4.2f", "float"},
// 		{"nanf", "float special"},
// 		{"+inff", "float special"},
// 		{"-inff", "float special"},
// 		{"4.2", "double"},
// 		{"-4.2", "double"},
// 		{"nan", "double special"},
// 		{"+inf", "double special"},
// 		{"-inf", "double special"},
// 		{"abc", "invalid"},
// 		{"42abc", "invalid"},
// 		{"1.2.3", "invalid"},
// 		{"", "invalid"},
// 		{"-+-1", "invalid"},
// 	};
// 	size_t test_count = sizeof(test) / sizeof(test[0]);
// 	for (size_t i = 0; i < test_count; ++i) {
// 		std::cout << "\x1b[33m----- Test: \"" << test[i].value << "\" " << test[i].text << " -----\x1b[39m" << std::endl;
// 		ScalarConverter::convert(test[i].value);
// 		std::cout << std::endl;
// 	}
// 	return 0;
// }
