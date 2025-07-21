#include"ScalarConverter.hpp"

/*
 * デフォルトコンストラクタ
 */
ScalarConverter::ScalarConverter() {}

/*
 * コピーコンストラクタ
 * コピー元のオブジェクトは既に有効な状態にあるはずなので、例外は投げない
 */
ScalarConverter::ScalarConverter(const ScalarConverter& copy) {
	(void)copy;
}

/*
 * コピー代入演算子 (A copy assignment operator overload.)
 */
ScalarConverter &ScalarConverter::operator=(const ScalarConverter& copy) {
	(void)copy;
	return (*this);
}

/*
 * デストラクタ
 */
ScalarConverter::~ScalarConverter() {}


// ↑↑↑ Orthodox Canonical Form --------------------------------------

bool	within_char_range(double num) {
	return (num >= 0 && num <= 127);
}

bool	within_int_range(double num) {
	return (num >= std::numeric_limits<int>::min() && num <= std::numeric_limits<int>::max());
}

bool	within_float_range(double num) {
	return (num >= -std::numeric_limits<float>::max() && num <= std::numeric_limits<float>::max());
}

double	convertDouble(const std::string& input) {
	double	value;

	std::stringstream iss(input);
	iss >> value;
	return (value);
}

void	convertStrToScalar(const std::string& str) {
	double value = convertDouble(str);
	std::cout << std::fixed << std::setprecision(1);

	//char変換
	if (within_char_range(value))
	{
		if (std::isprint(value))
			std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;

	//int変換
	if (within_int_range(value))
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;

	//float変換
	if (within_float_range(value))
		std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	else
		std::cout << "float: impossible" << std::endl;

	//double変換
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

// char/int/float/doubleの処理 ------------------------------------------------------------------------

void	outputChar(const std::string& input) {
	char value = static_cast<char>(input[0]);
	std::cout << "char: '" << value << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(value) << "" << std::endl;
	std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << "" << std::endl;
}

void	outputInt(const std::string& input) {
	convertStrToScalar(input);
}

void	outputFloat(const std::string& input) {
	if (input == "-inff" || input == "+inff" || input == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << input << std::endl;
		std::cout << "double: " << input.substr(0, input.size() - 1) << std::endl;
	}
	else
	{
		std::string without_f = input.substr(0, input.size() - 1);
		convertStrToScalar(without_f);
	}
}

void	outputDouble(const std::string& input) {
	if (input == "-inf" || input == "+inf" || input == "nan")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << input << "f" << std::endl;
		std::cout << "double: " << input << std::endl;
	}
	else
		convertStrToScalar(input);
}

// 型判定 ------------------------------------------------------------------------

bool parse_str_to_double(const std::string& str, double& value) {
	errno = 0;
	char* endptr;
	value = std::strtod(str.c_str(), &endptr);
	if (endptr == str.c_str() || *endptr != '\0')// 変換できていない場合
		return (false);
	if (errno == ERANGE)
	{
		if (value == 0.0)
			return (false);// doubleのアンダーフロー
		if (value == HUGE_VAL || value == -HUGE_VAL)
			return (false);// doubleのオーバーフロー
	}
	return (true);
}

bool	is_int(const std::string& input) {
	int	start = 0;
	if (input[0] == '-' || input[0] == '+')
		start++;
	for (size_t i = start; i < input.size(); i++)
	{
		if (!std::isdigit(input[i]))
			return (false);
	}
	double value;
	if (!parse_str_to_double(input, value))
		return (false);
	return (within_int_range(value));
}

bool	is_float(const std::string& input) {
	std::string without_f;
	if (input == "-inff" || input == "+inff" || input == "nanf")
		return (true);
	if (input.size() > 1 && input[input.size() - 1] == 'f')
	{
		without_f = input.substr(0, input.size() - 1);
		double value;
		if (!parse_str_to_double(without_f, value))
			return (false);
		return (within_float_range(value));
	}
	return (false);
}

bool	is_double(const std::string& input) {
	if (input == "-inf" || input == "+inf" || input == "nan")
		return (true);
	if (input.size() > 1)
	{
		double value;
		if (!parse_str_to_double(input, value))
			return (false);
		return (true);
	}
	return (false);
}

// メイン関数 ------------------------------------------------------------------------

void	ScalarConverter::convert(const std::string& input) {
	if (input.size() == 1 && !std::isdigit(input[0]))
		outputChar(input);
	else if (is_int(input))
		outputInt(input);
	else if (is_float(input))
		outputFloat(input);
	else if (is_double(input))
		outputDouble(input);
	else
	{
		std::cout << "char: invalid" << std::endl;
		std::cout << "int: invalid" << std::endl;
		std::cout << "float: invalid" << std::endl;
		std::cout << "double: invalid" << std::endl;
	}
}
