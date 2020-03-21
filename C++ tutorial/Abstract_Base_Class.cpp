/* Giả sử có 20 ô, mỗi ô có thể nuôi 1 con chó hoặc 1 con mèo.
Yêu cầu xây dựng chương trình gồm các chức năng:
Nhập con vật mới mua vào ô rỗng đầu tiên;
Xuất (đem bán) một con vật;
Thống kê các con vật trong 20 ô */

#include <iostream>
#include <ctype.h>
#include <string.h>

using namespace std;

class CON_VAT
{
    protected:
        char *ten;                          // ten con vat
    public:
        CON_VAT()
        {
            this->ten = NULL;
        }
        CON_VAT(char *ten1)
        {
            this->ten = strdup(ten1);
        }
        virtual void xung_ten()             // khong dung phuong thuc thuan tuy ao de co the khai bao doi tuong class CON_VAT
        {
            // phương thức xưng tên
        }
};

class CON_MEO : public CON_VAT
{
public:
    CON_MEO() : CON_VAT()
    {

    }
    CON_MEO(char *ten1) : CON_VAT(ten1)
    {
        //this->ten = strdup(ten1) ==> khong can gan "ten" vi ta da ke thua o class CON_VAT
    }
    virtual void xung_ten();
};
void CON_MEO::xung_ten()
{
    cout << "\nToi la con meo co ten la: " << ten;
}

class CON_CHO : public CON_VAT
{
public:
    CON_CHO() : CON_VAT()
    {

    }
    CON_CHO(char *ten1) : CON_VAT(ten1)
    {
        //this->ten = strdup(ten1) ==> khong can gan "ten" vi ta da ke thua o class CON_VAT
    }
    virtual void xung_ten();
};
void CON_CHO::xung_ten()
{
    cout << "\nToi la con cho co ten la: " << ten;
}

class DS_CON_VAT
{
    private:
        int so_luong_con_vat_max;
        int so_con_vat;
        CON_VAT **cv;                        // danh sach chua dia chi con vat
    public:
        DS_CON_VAT(int MAX);
        ~DS_CON_VAT();
        int nhap(CON_VAT *c);               // nhap xong tra ve vi tri con vat vua nhap
        CON_VAT* xuat(int n);               // xuat con vat dua tren vi tri cua no
        void thong_ke();
};
DS_CON_VAT::DS_CON_VAT(int MAX)
{
    this->so_luong_con_vat_max = MAX;
    this->so_con_vat = 0;
    cv = new CON_VAT* [so_luong_con_vat_max];
    for (int i = 0; i < so_luong_con_vat_max; ++i)
    {
        cv[i] = NULL;
    }
}

DS_CON_VAT::~DS_CON_VAT()
{
    this->so_luong_con_vat_max = this->so_con_vat = 0;
    delete cv;
}

int DS_CON_VAT::nhap(CON_VAT *c)
{
    if(so_con_vat == so_luong_con_vat_max) return 0;
    int i = 0;
    while(cv[i] != NULL) ++i;
    cv[i] = c;                              // vi la so sanh dia chi voi nhau nen khong can overload operator
    so_con_vat++;
    return i;
}

CON_VAT* DS_CON_VAT::xuat(int n)
{
    if (n < 0 || n > so_luong_con_vat_max)
    {
        return NULL;
    }
    if(cv[n])
    {
        CON_VAT *c = cv[n];
        cv[n] = NULL;
        so_con_vat--;
        return c;
    }
    else return NULL;
}

void DS_CON_VAT::thong_ke()
{
    if(so_con_vat)
    {
        for (int i = 0; i < so_luong_con_vat_max; ++i)
        {
            if(cv[i])
                cv[i]->xung_ten();
        }
    }
}

CON_CHO c1((char*)"MUC");
CON_CHO c2((char*)"VEN");
CON_CHO c3((char*)"LAI");
CON_CHO c4((char*)"NHAT");
CON_CHO c5((char*)"BONG");
CON_MEO m1((char*)"MUOP");
CON_MEO m2((char*)"DEN");
CON_MEO m3((char*)"TRANG");
CON_MEO m4((char*)"TAM THE");
CON_MEO m5((char*)"VANG");

int main(int argc, char const *argv[])
{
    DS_CON_VAT ds(20);

    cout << "\n----Thong ke lan 1----";
    int im2 = ds.nhap(&m2);
    ds.nhap(&c3);
    ds.nhap(&m1);
    int ic4 = ds.nhap(&c4);
    ds.nhap(&c5);
    ds.nhap(&m5);
    ds.nhap(&c2);
    ds.nhap(&m3);
    ds.thong_ke();

    cout << "\n----Thong ke lan 2----";
    ds.xuat(im2);                   // xuat DEN
    ds.xuat(ic4);                   // xuat NHAT
    ds.thong_ke();

    cout << endl << &c3;
    return 0;
}
