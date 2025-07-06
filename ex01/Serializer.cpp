#include"Serializer.hpp"

/*
 * デフォルトコンストラクタ
 */
Serializer::Serializer() {}

/*
 * コピーコンストラクタ
 * コピー元のオブジェクトは既に有効な状態にあるはずなので、例外は投げない
 */
Serializer::Serializer(const Serializer& copy) {
	(void)copy;
}

/*
 * コピー代入演算子 (A copy assignment operator overload.)
 */
Serializer &Serializer::operator=(const Serializer& copy) {
	(void)copy;
	return (*this);
}

/*
 * デストラクタ
 */
Serializer::~Serializer() {}


// ↑↑↑ Orthodox Canonical Form --------------------------------------


uintptr_t Serializer::serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}

