#ifndef BO_MON_H
#define BO_MON_H

#include "giao_vien.h"
#include <iostream>
#include <string.h>

using namespace std;
class BO_MON
{
    private:
        char bo_mon[20];                // Ten bo mon
        int n;                          // So giao vien
        GIAO_VIEN *gv;                  // Danh sach giao vien
    public:
        BO_MON()
        {
            bo_mon[0] = 0;
            gv = NULL;
            n = 0;
        }
        void nhap()
        {
            cout << "\nNhap bo mon: ";
            fflush(stdin);
            fgets(bo_mon, 20, stdin);

            cout << "So giao vien: ";
            cin >> n;
            cin.ignore();

            if(gv) delete gv;
            if(n)
            {
                gv = new GIAO_VIEN[n];
                for (int i = 0; i < n; ++i)
                {
                    gv[i].nhap();
                }
            }
        }
        void xuat()
        {
            cout << "\nTen bo mon: " << bo_mon;
            cout << "\nSo giao vien: " << n;
            if(n)
            {
                cout << "\nDanh sach giao vien cua bo mon: ";
                for (int i = 0; i < n; ++i)
                    {
                        gv[i].xuat();
                    }
            }
        }
        void sapxep()
        {
            GIAO_VIEN tg;
            if(n)
            {
                for (int i = 0; i < n; ++i)
                {
                    for (int j = 0; j < n; ++j)
                    {
                        if (gv[i].getSm() < gv[j].getSm())
                        {
                            tg = gv[i]; gv[i] = gv[j]; gv[j] = tg;
                        }
                    }
                }
            }
        }
};

#endif
