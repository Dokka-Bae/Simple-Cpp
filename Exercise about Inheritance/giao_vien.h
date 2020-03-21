#ifndef GIAO_VIEN_H
#define GIAO_VIEN_H

#include "mon_hoc.h"
#include <iostream>
#include <string.h>

using namespace std;
class GIAO_VIEN
{
    private:
        char ht[20];                    // Ho ten
        int ns;                         // Nam sinh
        int sm;                         // So mon hoc co the day
        MON_HOC *mh;
    public:
        GIAO_VIEN()
        {
            ht[0] = 0;
            ns = sm = 0;
            mh = NULL;
        }
        ~GIAO_VIEN()
        {
            ht[0] = ns = sm = 0;
            if(mh) delete mh;
        }
        int getSm()
        {
            return sm;
        }
        const GIAO_VIEN& operator=(const GIAO_VIEN& gv)
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
        void nhap()
        {
            cout << "\nHo ten: ";
            fgets(ht, 20, stdin);
            cout << "\nNam sinh: "; cin >> ns;
            cout << "\nSo mon: "; cin >> sm; cin.ignore();
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
        void xuat()
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
};

#endif
