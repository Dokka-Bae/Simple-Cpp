//Inhalt: Nhap 1 day cac diem, sau do tim tam giac lon nhat ve dien tich co dinh la cac diem vua nhap

#include <iostream>
#include <math.h>
using namespace std;

class DIEM
{
    private:
        double x, y;                        // toa do cac diem
    public:
        void nhapsl()
        {
            cout << "Toa do x va y: ";
            cin >> x >> y;
        }

        void in()
        {
            cout << "x = " << x << " y = " << y;
        }

        double do_dai(DIEM d2)
        {
            return sqrt(pow(x - d2.x, 2) + pow(y - d2.y, 2));
        }
};

class TAM_GIAC
{
    private:
        DIEM d1, d2, d3;                    // 3 dinh tam giac
    public:
        void in();
        static TAM_GIAC tao_tg(DIEM e1, DIEM e2, DIEM e3)
        {
            TAM_GIAC tg;

            tg.d1 = e1;
            tg.d2 = e2;
            tg.d3 = e3;

            return tg;
        }
        double dien_tich();
        TAM_GIAC tg_dt_max(TAM_GIAC t2);    // tim tam giac co dien tich max va tra no ve kieu tam giac
};

void TAM_GIAC::in()
{
    cout << "\nDinh 1: "; d1.in();
    cout << "\nDinh 2: "; d2.in();
    cout << "\nDinh 3: "; d3.in();
}

double TAM_GIAC::dien_tich()
{
    double a, b, c, p, s;

    a = d1.do_dai(d2);
    b = d2.do_dai(d3);
    c = d3.do_dai(d1);

    p = (a + b + c) / 2;
    s = sqrt(p * (p-a) * (p-b) * (p-c));

    return s;
}

TAM_GIAC TAM_GIAC::tg_dt_max(TAM_GIAC t2)
{
    if(this -> dien_tich() > t2.dien_tich())
        return *this;
    else
        return t2;
}

int main()
{
    DIEM d[50];
    int n;

    cout << "\nSo diem: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cout << "\nNhap diem " << i << " : ";
        d[i].nhapsl();
    }

    int j, k;
    TAM_GIAC tmax, t;
    tmax = TAM_GIAC::tao_tg(d[1], d[2], d[3]);
    for (int i = 0; i < n-2; i++)
        for (int j = i+1; j < n-1; j++)
            for (int k = j+1; k < n; k++)
            {
                t = TAM_GIAC::tao_tg(d[i], d[j], d[k]);
                tmax = tmax.tg_dt_max(t);
            }

    cout << "\nTam giac co dien tich lon nhat --- \n"; tmax.in();
    cout << "\nDien tich lon nhat: " << tmax.dien_tich();

    return 0;
}

