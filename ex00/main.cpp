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
// 		{"127", "int (char max)"},
// 		{"128", "int (char max + 1)"},
// 		{"2147483647", "int max"},
// 		{"-2147483648", "int min"},
// 		{"2147483648", "int max + 1"},
// 		{"-2147483649", "int min - 1"},
// 		{"3.4e49", "float overflow"},
// 		{"3.4e-49", "float underflow"},
// 		{"1e400", "double overflow"},
// 		{"1e-400", "double underflow"},
// 	};
// 	size_t test_count = sizeof(test) / sizeof(test[0]);
// 	for (size_t i = 0; i < test_count; ++i) {
// 		std::cout << "\x1b[33m----- Test: \"" << test[i].value << "\" " << test[i].text << " -----\x1b[39m" << std::endl;
// 		ScalarConverter::convert(test[i].value);
// 		std::cout << std::endl;
// 	}
// 	return 0;
// }
