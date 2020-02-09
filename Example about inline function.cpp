#include <iostream>

using namespace std;

int f(int a);
inline void f(int a);

int f(int a)
{
	return a*a;
}

void f(int a)
{
	cout <<"\n" << a;
}

int main()
{
	int b = f(5);
	f(6);
	
	return 0;
}
