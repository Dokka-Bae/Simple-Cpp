#include <iostream>

using namespace std;
int f(int n);
int f(int n = 1200)
{
	return n;
}

int main()
{
	cout << f(1400); // In ra ket qua 1400
	
	return 0;
}
