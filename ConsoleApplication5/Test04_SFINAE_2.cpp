#include <type_traits>

//��|�C���^�p
template<class T, std::enable_if_t<!std::is_pointer<T>::value>* = nullptr>void f(T a)
{
}
//�|�C���^�p
template<class T, std::enable_if_t< std::is_pointer<T>::value>* = nullptr>void f(T a)
{
}

int main()
{
	f(123);//int �^���� (T = int)
	f(0.123); // double �^���� (T = double)
	f(""); //const char* �^���� (T = const char*)



}
