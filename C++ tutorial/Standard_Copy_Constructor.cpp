#include <iostream>

using namespace std;

class DT
{
    private:
        int n;                                                      // Bac da thuc
        double *a;                                                  // Tro toi vung nho chua cac he so a0, a1, a2 cua da thuc
    public:
        DT()                                                        // O bai nay ta van se dung ham tao mac dinh
        {
            this -> n = 0;
            this -> a = NULL;
        }
        DT(int n1)
        {
            this -> n = n1;
            this -> a = new double[n1];
        }
        DT(const DT &d);                                            // Ham sao chep duoc dung thay the cho ham sao chep mac dinh
        friend ostream& operator<< (ostream& os, const DT &d);
        friend istream& operator>> (istream& is, DT &d);
};

DT::DT(const DT &d)
{
    this -> n = d.n;
    this -> a = new double[d.n];
    for (int i = 0; i < d.n; i++)
    {
        this -> a[i] = d.a[i];
    }
}

ostream& operator<< (ostream& os, const DT &d)
{
    cout << "\nCac he so: ";
    for (int i = 0; i < d.n; i++)
    {
        os << d.a[i] << " ";
    }
    return os;
}

istream& operator>> (istream& is, DT &d)
{
    if(d.a != NULL) delete d.a;
    cout << "\nBac cua da thuc: "; cin >> d.n;
    d.a = new double[d.n];
    cout << "\n---Nhap cac he so--- ";
    for (int i = 0; i < d.n; i++)
    {
        cout << "\nHe so bac " << i << ": ";
        is >> d.a[i];
    }
    return is;
}

int main()
{
    DT d;
    cout << "\n---Nhap da thuc d--- "; cin >> d;
    cout << "Da thuc d: " << d;

    DT u(d);
    cout << "\nDa thuc u truoc khi sua doi d: " << u;
    cout << "\n---Sua doi da thuc d--- "; cin >> d;
    cout << "\nDa thuc d sau khi sua doi: " << d;
    cout << "\nDa thuc u sau khi da thuc d sua doi " << u;

    return 0;
}








