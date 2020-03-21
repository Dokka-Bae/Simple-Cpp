#include <iostream>
#include "giao_vien.h"
#include <string.h>

using namespace std;

const GIAO_VIEN& GIAO_VIEN::operator=(const GIAO_VIEN& gv)
{
    strcpy(this->ht, gv.ht);
    this->ns = gv.ns;
    this->sm = gv.sm;
    if(this->mh) delete this->mh;
    if(this->sm)
    {
        this->mh = new MON_HOC[this->sm];
        for (int i = 0; i < this->sm; ++i)
        {
            this->mh[i] = gv.mh[i];
        }
    }
    return gv;
}

void GIAO_VIEN::nhap()
{
    cout << "\nHo va ten: ";
    fflush(stdin); cin.getline(ht,sizeof(ht));
    cout << "\nNam sinh: "; cin >> ns;
    cout << "\nSo mon: "; cin >> sm;
    if(this->mh) delete this->mh;
    if(sm)
    {
        this->mh = new MON_HOC[sm];
        for (int i = 0; i < sm; ++i)
        {
            this->mh[i].nhap();
        }
    }
}

void GIAO_VIEN::xuat()
{
    cout << "\nHo va ten: " << ht;
    cout << "\nNam sinh: " << ns;
    cout << "\nSo mon: " << sm;
    if (sm)
    {
        cout << "\nMon hoc dang phu trach la: ";
        for (int i = 0; i < sm; ++i)
        {
            this->mh[i].xuat();
            cout << " ";
        }
    }
}
