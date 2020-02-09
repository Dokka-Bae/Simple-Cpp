/* Calculate s = (p - q * z) / (u + v) in writing form */

#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;

typedef struct
{
	int a, b;
} PS;

ostream& operator<< (ostream& os, PS p);
istream& operator>> (istream& is, PS &p);

int uscln(int x, int y);
PS rutgon(PS p);
PS operator+(PS p1, PS p2);
PS operator-(PS p1, PS p2);
PS operator*(PS p1, PS p2);
PS operator/(PS p1, PS p2);

ostream &operator<< (ostream& os, PS p)
{
	os << p.a << '/' << p.b;
	return os;
}

istream &operator>> (istream& is, PS &p)
{
	is >> p.a >> p.b;
	return is;
}

int uscln(int x, int y)
{
	x = abs(x);  y = abs(y);
	if (x*y == 0) return 1;
		while(x != y)
		{
			if (x > y) 
				x -= y;
			else 	   
				y -= x;
		}
	return x;
}

PS rutgon(PS p)
{
	PS q;
	int x = uscln(p.a, p.b);
	q.a = p.a / x;
	q.b = p.b / x;
	return q;
}

PS operator+(PS p1, PS p2)
{
	PS q;
	q.a = p1.a * p2.b + p2.a * p1.b;
	q.b = p1.b * p2.b;
	return rutgon(q);
}

PS operator-(PS p1, PS p2)
{
	PS q;
	q.a = p1.a * p2.b - p2.a * p1.b;
	q.b = p1.b * p2.b;
	return rutgon(q);
}

PS operator*(PS p1, PS p2)
{
	PS q;
	q.a = p1.a * p2.a;
	q.b = p1.b * p2.b;
	return rutgon(q);
}

PS operator/(PS p1, PS p2)
{
	PS q;
	q.a = p1.a * p2.b;
	q.b = p1.b * p2.a;
	return rutgon(q);
}

int main()
{
	PS s, p, q, z, u, v;
	
	cout << "Nhap cac tham so: ";
	cin >> p >> q >> z >> u >> v; // luc nhap thi nhap a, space ,b ==> a/b
	
	s = (p - q * z) / (u + v);
	
	cout << "Ket qua: " << s;
	
	return 0;
}
