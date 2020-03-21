#include <iostream>
using namespace std;

class HINH_CN
{
    private:
        int d, r; // bien chieu dai va chieu rong
    public:
        inline void nhapsl();
        inline void in();
        inline int dien_tich();
        inline int chu_vi();
};

void HINH_CN::nhapsl()
{
    cout << "\nNhap chieu dai: ";  cin >> d;
    cout << "\nNhap chieu rong: "; cin >> r;
}

void HINH_CN::in()
{
    cout << "\nChieu dai: "  << d;
    cout << "\nChieu rong: " << r;
}

int HINH_CN::dien_tich()
{
    return d*r;
}

int HINH_CN::chu_vi()
{
    return 2*(d+r);
}

class DAY_HINH_CN
{
    private:
        int n;                              // so luong hinh chu nhat
        HINH_CN *h;
    public:
        void nhapdaysl();                      // nhap mot day hinh chu nhat
        HINH_CN hinh_dt_max();              // tra ve hinh chu nhat co dien tich max
        HINH_CN *hinh_cv_max();             // tra ve hinh chu nhat co chu vi max
};

void DAY_HINH_CN::nhapdaysl()
{
    cout << "So hinh chu nhat: ";
    cin >> n;
    h = new HINH_CN[n];
    for (int i = 0; i < n; i++)
    {
        h[i].nhapsl();
    }
}

HINH_CN DAY_HINH_CN::hinh_dt_max()
{
    HINH_CN hdtmax;
    hdtmax = h[0];
    for (int i = 1; i < n; i++)
    {
        if(h[i].dien_tich() > hdtmax.dien_tich()) hdtmax = h[i];
    }
    return hdtmax;
}

HINH_CN *DAY_HINH_CN::hinh_cv_max()
{
    int imax = 0;
    for (int i = 1; i < n; i++)
    {
        if(h[i].chu_vi() > h[imax].chu_vi()) imax = i;
    }
    return (h + imax);
}

int main()
{
    DAY_HINH_CN arr;
    arr.nhapdaysl();

    HINH_CN hcn_dt_max;
    hcn_dt_max = arr.hinh_dt_max();
    hcn_dt_max.in();

    HINH_CN *hcn_cv_max;
    hcn_cv_max = arr.hinh_cv_max();
    hcn_cv_max -> in();

    return 0;
}
