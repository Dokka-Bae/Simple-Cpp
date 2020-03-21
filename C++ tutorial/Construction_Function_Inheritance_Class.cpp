#include <iostream>
#include <string.h>
using namespace std;

class NGUOI
{
    private:
        char *ht;                       // Ho ten
        int ns;                         // Nam sinh
    public:
        NGUOI()
        {
            ht = NULL;
            ns = 0;
        }
        NGUOI(char *ht1, int ns1)
        {
            int n = strlen(ht1);
            ht = new char[n];
            strcpy(ht, ht1);

            ns = ns1;
        }
        ~NGUOI()
        {
            if(ht != NULL)
            {
                delete ht;
                ns = 0;
            }
        }

        void in()
        {
            cout << "\nHo va ten: " << ht << "\nNam sinh: " << ns;
        }
};

class MON_HOC
{
    private:
        char *mon_hoc;                    // Ten mon hoc
        int st;                           // So tiet
    public:
        MON_HOC()
        {
            mon_hoc = NULL;
            st = 0;
        }
        MON_HOC(char *mon_hoc_1, int st1)
        {
            int n = strlen(mon_hoc_1);
            mon_hoc = new char[n];
            strcpy(mon_hoc, mon_hoc_1);

            st = st1;
        }
        ~MON_HOC()
        {
            if(mon_hoc != NULL)
            {
                delete mon_hoc;
                st = 0;
            }
        }

        void in()
        {
            cout << "\nMon hoc: " << mon_hoc << "\nSo tiet: " << st;
        }
};

class GIAO_VIEN : public NGUOI
{
    private:
        char *bo_mon;                   // Bo mon cong tac
        MON_HOC mh;
    public:
        GIAO_VIEN() : mh(), NGUOI()
        {
            bo_mon = NULL;
        }
        GIAO_VIEN(char *ht1, int ns1, char *mon_hoc_1, int st1, char *bo_mon_1) : NGUOI(ht1, ns1), mh(mon_hoc_1, st1)
        {
            int n = strlen(bo_mon_1);
            bo_mon = new char[n];
            strcpy(bo_mon, bo_mon_1);
        }
        ~GIAO_VIEN()
        {
            if(bo_mon != NULL)
            {
                delete bo_mon;
            }
        }
        void in()
        {
            NGUOI::in();
            cout << "\nCong tac bo mon: " << bo_mon;
            mh.in();
        }
};

int main(int argc, char const *argv[])
{
    GIAO_VIEN *gv;
    gv = new GIAO_VIEN("DO VAN HUNG", 1997, "TINHOCDAICUONG", 15, "TINHOC");

    gv->in();
    gv->NGUOI::in();

    return 0;
}



