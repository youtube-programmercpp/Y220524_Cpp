#include <type_traits>

//非ポインタ用
template<class T, std::enable_if_t<!std::is_pointer<T>::value>* = nullptr>void f(T a)
{
}
//ポインタ用
template<class T, std::enable_if_t< std::is_pointer<T>::value>* = nullptr>void f(T a)
{
}

int main()
{
	f(123);//int 型引数 (T = int)
	f(0.123); // double 型引数 (T = double)
	f(""); //const char* 型引数 (T = const char*)



}
