/* link bai tap: https://nguyenvanhieu.vn/bai-tap-lap-trinh-huong-doi-tuong/ */

#include <iostream>
#include <string.h>

using namespace std;

class Date
{
    protected:
        int day, month, year;

    public:
        Date()
        {
            this->day = this->month = this->year = 0;
        }
        ~Date()
        {
            this->day = this->month = this->year = 0;
        }
        void input()
        {
            cout << "Nhap Ngay: ";
            cin >> this->day;
            cout << "Nhap Thang: ";
            cin >> this->month;
            cout << "Nhap Nam: ";
            cin >> this->year;
        }
        void output()
        {
            cout << "Ngay/Thang/Nam: " << this->day << "/" << this->month << "/" << this->year << endl;
        }
};


class Vemaybay
{
    private:
        string tenchuyen;
        Date ngaybay;
        int giave;
    public:
        Vemaybay()
        {
            this->tenchuyen = "";
            this->giave = 0;
        }
        ~Vemaybay()
        {
            this->tenchuyen = "";
            this->giave = 0;
        }
        friend ostream& operator<<(ostream &os, Vemaybay &vmb);
        friend istream& operator>>(istream &is, Vemaybay &vmb);
        inline int returnGiave();
};

ostream& operator<<(ostream &os, Vemaybay &vmb)
{
    cout << "Ten Chuyen: " << vmb.tenchuyen << endl;
    cout << "Ngay Bay: " << endl << "\t";
    vmb.ngaybay.output();
    cout << "Gia Ve: " << vmb.giave << endl;

    return os;
}

istream& operator>>(istream &is, Vemaybay &vmb)
{
    cin.ignore();
    cout << "Nhap Ten Chuyen: "; fflush(stdin); getline(cin, vmb.tenchuyen);
    cout << "Nhap Ngay Bay: " << endl;
    vmb.ngaybay.input();
    cout << "Nhap Gia Ve: "; cin >> vmb.giave;

    return is;
}

int Vemaybay::returnGiave()
{
    return this->giave;
}

class Nguoi
{
    protected:
        string hoten, gioitinh;
        int tuoi;
    public:
        Nguoi()
        {
            this->hoten = this->gioitinh = "";
            this->tuoi = 0;
        }
        ~Nguoi()
        {
            this->hoten = this->gioitinh = "";
            this->tuoi = 0;
        }
        friend ostream& operator<<(ostream &os, Nguoi &ng);
        friend istream& operator>>(istream &is, Nguoi &ng);
};

ostream& operator<<(ostream &os, Nguoi &ng)
{
    cout << "Ho Ten: " << ng.hoten << endl;
    cout << "Gioi Tinh: " << ng.gioitinh << endl;
    cout << "Tuoi: " << ng.tuoi << endl;

    return os;
}
istream& operator>>(istream &is, Nguoi &ng)
{
    cin.ignore();
    cout << "Nhap Ho Ten: "; fflush(stdin); getline(cin, ng.hoten);
    cout << "Nhap Gioi Tinh: "; fflush(stdin); getline(cin, ng.gioitinh);
    cout << "Nhap Tuoi: "; cin >> ng.tuoi;

    return is;
}

class HanhKhach : public Nguoi
{
private:
    Vemaybay *ve;
    int soluong;
    int tongtien;
    Nguoi ng;
public:
    HanhKhach()
    {
        this->soluong = this->tongtien = 0;
        this->ve = NULL;
    }
    ~HanhKhach()
    {
        this->hoten = "";
        this->gioitinh = "";
        this->tuoi = 0;
        this->soluong = 0;
        this->tongtien = 0;
        if (ve) delete[] ve;
        // if(ve) delete ve; ==> delete ve cause error: free() invalid pointer
    }
    void input()
    {
        cin >> ng;
        cout << "Nhap So Luong Ve Hanh Khach Da Mua: "; cin >> this->soluong;
        ve = new Vemaybay[this->soluong];
        for (int i = 0; i < this->soluong; ++i)
        {
            cin >> ve[i];
            tongtien += ve[i].returnGiave();
        }
    }
    void output()
    {
        cout << "- Thong Tin Khach Hang: " << endl;
        cout << ng;
        cout << "- Thong Tin Chuyen Bay: " << endl;
        for (int i = 0; i < this->soluong; ++i)
        {
            cout << ve[i] << endl;
        }
        cout << "==> Tong Tien = " << this->tongtien << endl;
    }
    bool operator < (const HanhKhach &hk)
    {
        if(this->tongtien < hk.tongtien) return true;
        else return false;
    }
};

void swap(HanhKhach &a, HanhKhach &b)
{
    HanhKhach temp;
    temp = b;
    b = a;
    a = temp;
}

void BubbleSort(HanhKhach arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j)
            if (arr[j] < arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

int main(int argc, char const *argv[])
{
    int n;
    cout << "\n Nhap so luong hanh khach: "; cin >> n;
    HanhKhach *arr = new HanhKhach[n];

    for (int i = 0; i < n; ++i)
    {
        arr[i].input();
    }

    cout << "\n----------Before sort---------------" << endl;
    for (int i = 0; i < n; ++i)
    {
        arr[i].output();
    }

    cout << "\n----------After sort---------------" << endl;
    BubbleSort(arr, n);
    for (int i = 0; i < n; ++i)
    {
        arr[i].output();
    }
    return 0;
}
