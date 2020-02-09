#include <iostream>

using namespace std;

struct TS 
{
	char ht[25];
	float t, l, h, td;
} *ts;

void cap_phat_bo_nho_nhapdl(int n)
{
	ts = new TS[n+1];
	if (ts == NULL)
	{
		cout << "Loi cap phat bo nho.";
	}
	for (int i = 0; i < n; i++)
	{
		TS &h = ts[i];
		cout << "\nThi sinh thu: " << i+1;
		cout << "\nHo va ten: ";
		cin.ignore(1);
		cin.get(h.ht, 25);
		
		cout << "\nCac diem toan, ly, hoa: ";
		cin >> h.t >> h.l >> h.h;
		h.td = h.t + h.l + h.h;
		cout << "\nTong diem: " << h.td;
	}
}

TS &f(int i, int n)
{
	if (i < 1 || i > n)
	{
		cout << "Chi so mang khong hop le.";
		exit(1);
	}
	return ts[i];
}

int main()
{
	int n, i;
	cout << "Nhap so hoc vien: ";
	cin >> n;
	cap_phat_bo_nho_nhapdl(n);
	while(1)
	{
		cout << "\nCan xem hoc vien so may: ";
		cin >> i;
		
		TS &h = f(i+1, n);
		cout << "\nHo va ten: " << h.ht;
		cout << "\nTong diem: " << h.td;
	}
}
