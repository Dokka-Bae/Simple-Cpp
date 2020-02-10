#include <iostream>
#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

class DIEM
{
	private:
		int name;
		int x, y;
	public:
		void nhap_ten_dinh();
		void nhapsl();
		void ve_doan_thang(DIEM d2, int mau);
		void ve_tam_giac(DIEM d2, DIEM d3, int mau);
		double do_dai(DIEM d2);
		double chu_vi(DIEM d2, DIEM d3);
};

void DIEM::nhap_ten_dinh()
{
	cout <<"Nhap ten dinh: ";
	cin >> name;
}

void DIEM::nhapsl()
{
	cout <<"Nhap toa do tung do cua truc hoanh cua dinh " << this->name <<" :"; cin >> x;
	cout <<"Nhap toa do tung do cua truc tung cua dinh " << this->name <<" :";  cin >> y;
}

void kd_do_hoa()
{
	int mh, mode ;
	mh = mode = 0;
	initgraph(&mh, &mode, "");
}

void DIEM::ve_doan_thang(DIEM d2, int mau)
{
	setcolor(mau);
	line(this->x, this->y, d2.x, d2.y);	
}

void DIEM::ve_tam_giac(DIEM d2, DIEM d3, int mau)
{
	(*this).ve_doan_thang(d2, mau);
	d2.ve_doan_thang(d3, mau);
	d3.ve_doan_thang(*this, mau);
}

double DIEM::do_dai(DIEM d2)
{
	DIEM d1 = *this;
	return sqrt(pow(d1.x - d2.x, 2) + pow(d1.y - d2.y, 2));
}

double DIEM::chu_vi(DIEM d2, DIEM d3)
{
	return (*this).do_dai(d2) + d2.do_dai(d3) + d3.do_dai(*this);
}

int main()
{
	DIEM d1, d2, d3;
	char tb_cv[20];
	
	d1.nhap_ten_dinh();
	d2.nhap_ten_dinh();
	d3.nhap_ten_dinh();
	
	d1.nhapsl();
	d2.nhapsl();
	d3.nhapsl();
	
	d1.ve_tam_giac(d2, d3, 15);
	double cv = d1.chu_vi(d2, d3);
	
	sprintf(tb_cv, "Chu vi: %0.2f", cv);
	outtextxy(10, 10, tb_cv);
	
	closegraph();
	
	return 0;
}
