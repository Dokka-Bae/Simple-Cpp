#include <iostream>

using namespace std;

class PS
{
    private:
        int t, m; // tu va mau cua phan so
    public:
        friend ostream& operator<< (ostream& os, const PS &p)
        {
            os << p.t << "/" << p.m;
            return os;
        }
        friend istream& operator>> (istream& is, PS &p)
        {
            cout << " --> Nhap tu va mau: ";
            is >> p.t >> p.m;
            return is;
        }
};

int main()
{
    PS d;
    cout << "\nNhap PS d: "; cin >> d;
    cout << "\nPhan so d: " << d;

    PS u(d);
    cout << "\nPhan so u: " << u;

    return 0;
}
