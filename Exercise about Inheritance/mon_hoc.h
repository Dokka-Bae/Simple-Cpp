#ifndef MON_HOC_H
#define MON_HOC_H

#include <iostream>
#include <string.h>

using namespace std;

class MON_HOC
{
    private:
        char tenmh[20];                 // ten mon hoc
        int st;                         // so tiet
    public:
        MON_HOC()
        {
            tenmh[0] = 0;
            st = 0;
        }
        const MON_HOC &operator=(const MON_HOC &mh)
        {
            strcpy(this->tenmh, mh.tenmh);
            this->st = mh.st;
            return mh;
        }
        void nhap()
        {
            cout << "\nNhap ten mon hoc: ";
            fgets(tenmh, 20, stdin);
            cout << "\nSo tiet: ";
            cin >> st; cin.ignore();
        }
        void xuat()
        {
            cout << "\nTen mon hoc: " << tenmh;
            cout << "\nSo tiet: " << st;
        }
};

#endif
