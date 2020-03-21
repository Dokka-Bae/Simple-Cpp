// Inhalt: nhap 1 ma tran vuong cap n va 1 vec to cap n, sau do thuc hien phep nhan ma tran voi vecto vua nhap
// Achtung: ham ban muon truy cap thuoc tinh cua doi tuong thi phai goi doi tuong chua thuoc tinh do truoc
#include <iostream>
#include <math.h>
using namespace std;

class VT;
class MT;

class VT
{
    private:
        int n;
        double arr[20];
    public:
        void nhapsl();
        // ham ban voi lop VT de in vecto
        friend void in(const VT &x);
        // ham ban voi lop VT de nhan ma tran voi vecto
        friend VT tich(const VT &x, const MT &y);
};

class MT
{
    private:
        int n;
        double arr[20][20];
    public:
        void nhapsl();
        // ham ban voi lop MT de in ma tran
        friend void in(const MT &y);
        // ham ban voi lop VT de nhan ma tran voi vecto
        friend VT tich(const VT &x, const MT &y);
};

void VT::nhapsl()
{
    cout << "\nCap vec to: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thanh phan vecto thu " << i << " :";
        cin >> arr[i];
    }
}

void in(const VT &x)
{
    cout << "\n";
    for (int i = 0; i < x.n; i++)
    {
        cout << "Thanh phan vecto thu " << i << " : " << x.arr[i];
    }
}

VT tich(const VT &x, const MT &y)
{
    VT res;
    int n = res.n;
    if (n != x.n)
    {
        return x;
    }
    res.n = n;
    for (int i = 0; i < n; i++)
    {
        res.arr[i] = 0;
        for (int j = 0; j < n; j++)
        {
            res.arr[i] += y.arr[i][j] * x.arr[j];
        }
    }
    return res;
}

void MT::nhapsl()
{
    cout << "\nCap ma tran: ";
    cin >> n;
    cout << "\nNhap ma tran" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cout << "\nPhan tu hang thu " << i << " cot " << j << " = ";
            cin >> arr[i][j];
        }

}

void in (const MT &a)
{
    for (int i = 0; i < a.n; i++)
    {
        cout << "\n";
        for (int j = 0; j < a.n; j++)
        {
            cout << a.arr[i][j] << " ";
        }
    }

}

int main()
{
    VT vt, res;
    MT mt;

    vt.nhapsl();
    mt.nhapsl();

    in(vt);
    in(mt);

    res = tich(vt, mt);
    in(res);

    return 0;
}
