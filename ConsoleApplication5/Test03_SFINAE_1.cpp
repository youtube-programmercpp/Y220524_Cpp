template<int = 3/*��^�p�����[�^*/>void f();
template<>void f<3>()
{
}
template<>void f<4>()
{
}
template<>void f<5>()
{
}
int main()
{
	f();
	f<5>();
	f<3>();
}
