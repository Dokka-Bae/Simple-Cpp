// Nhap mot danh sach thi sinh, sap xep theo thu tu giam dan cua tong diem

#include <iostream>
#include <string.h>
using namespace std;

class TS
{
    private:
        char *ht;                               // Ho ten cua thi sinh
        double td;                              // Tong diem cua thi sinh
    public:
        TS()
        {
            ht = new char[20];
            td = 0;
        }
        ~TS()
        {
            delete ht;
        }

        const TS &operator=(const TS &ts2)      // Tra ve tham chieu doi tuong nguon de co the gan dc cho nhieu doi tuong dich
        {
            strcpy(this->ht, ts2.ht);
            this->td = ts2.td;
            return ts2;
        }

        inline void in();
        void nhap(int i);
        void hv(TS &ts2);
        double gettd()
        {
            return td;
        }
};

void TS::in()
{
    cout << "\nHo ten: " << ht << " -- Tong diem: " << td;
}

void TS::nhap(int i)
{
    cout << "\nNhap thi sinh " << i+1;
    cout << "\nHo va ten: "; cin >> ht;
    cout << "\nTong diem: "; cin >> td;
}

void TS::hv(TS &ts2)
{
    TS tg;
    tg = *this;
    *this = ts2;
    ts2 = tg;
}

int main(int argc, char const *argv[])
{
    int n, j;
    cout << "\nNhap so thi sinh: "; cin >> n;

    TS *ts;                                         // Thiet lap mang doi tuong
    ts = new TS[n];

    for(int i = 0; i < n; i++)
    {
        ts[i].nhap(i);
        ts[i].in();
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            if(ts[i].gettd() < ts[j].gettd())
                ts[i].hv(ts[j]);
        }
    }


    cout << "\nDanh sach sau khi sap xep";
    for (int i = 0; i < n; i++)
    {
        ts[i].in();
    }

    return 0;
}
