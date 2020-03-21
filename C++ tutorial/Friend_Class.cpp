/* Nhap cac ma tran A, B, C; nhap cac vecto; tinh tich D = AB, u = Dy, v = xC, s = vu*/
/* Tao 2 class VT, MT */

#include <iostream>
using namespace std;

class MT;
class VT;

class MT
{
    private:
        int n;
        double mt[10][10];
    public:
        friend class VT;
        MT()
        {
            this->n = 0;
        }

        void nhap();
        void in();
        VT tich(const VT &a);
        MT tich(const MT &b);
};

class VT
{
private:
    int n;
    double vt[10];
public:
    friend class MT;
    VT()
    {
        this->n = 0;
    }

    void nhap();
    void in();

    VT tich(const MT &a);
    double tich(const VT &b);
};

void MT::nhap()
{
    cout << "\nNhap cap ma tran: "; cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << "\nPhan tu hang thu " << i << " ," << j << " la: ";
            cin >> mt[i][j];
        }
    }
}

void MT::in()
{
    for (int i = 0; i < n; ++i)
    {
        cout << "\n";
        for (int j = 0; j < n; ++j)
        {
            cout << mt[i][j] << " ";
        }
    }
}

void VT::nhap()
{
    cout << "\nNhap cap ma tran: "; cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cout << "\nPhan tu thu " << i << " : ";
        cin >> vt[i];
    }
}

void VT::in()
{
    for (int i = 0; i < n; ++i)
    {
        cout << vt[i] << " ";
    }
}

VT MT::tich(const VT &a)
{
    VT res;
    for (int i = 0; i < n; ++i)
    {
        res.vt[i] = 0.0;
        for (int j = 0; j < n; ++j)
        {
            res.vt[i] += mt[i][j] * a.vt[i];
        }
    }
    res.n = n;
    return res;
}

MT MT::tich(const MT &b)
{
    MT res;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            res.mt[i][j] = 0.0;
            for (int k = 0; k < n; ++k)
            {
                res.mt[i][j] += mt[i][k] * b.mt[i][j];
            }
        }
    res.n = n;
    return res;
}

VT VT::tich(const MT &a)
{
    VT res;
    for (int i = 0; i < n; ++i)
    {
        res.vt[i] = 0.0;
        for (int j = 0; j < n; ++j)
        {
            res.vt[j] += a.mt[j][i] * vt[j];
        }
    }
    res.n = n;
    return res;
}

double VT::tich(const VT &b)
{
    double res = 0.0;
    for (int i = 0; i < n; ++i)
    {
        res += vt[i] * b.vt[i];
    }
    return res;
}

int main(int argc, char const *argv[])
{
    MT a, b, c;
    VT x, y;

    cout << "\nMa tran A: ";
    a.nhap();
    cout << "\nMa tran B: ";
    b.nhap();
    cout << "\nMa tran C: ";
    c.nhap();

    cout << "\nVecto X: ";
    x.nhap();
    cout << "\nVecto Y: ";
    y.nhap();

    MT d = a.tich(b);
    VT u = d.tich(y);
    VT v = x.tich(c);
    double s = v.tich(u);

    cout << "\nVecto v: ";
    v.in();
    cout << "\nVecto y: ";
    y.in();
    cout << "\nMa tran D: ";
    d.in();
    cout << "\nS = vDy = " << s;

    return 0;
}

















