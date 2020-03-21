/* link bai tap: https://nguyenvanhieu.vn/bai-tap-lap-trinh-huong-doi-tuong/ */

#include <iostream>
#include <string.h>

using namespace std;

class VanDongVien
{
private:
    string hoten;
    int tuoi;
    string monthidau;
    float cannang;
    float chieucao;
public:
    VanDongVien()
    {
        this->hoten = "";
        this->tuoi = 0;
        this->monthidau = "";
        this->cannang = 0.0;
        this->chieucao = 0.0;
    }
    VanDongVien(string hoten1, int tuoi1, string monthidau1, float cannang1, float chieucao1)
    {
        this->hoten = hoten1;
        this->tuoi = tuoi1;
        this->monthidau = monthidau1;
        this->cannang = cannang1;
        this->chieucao = chieucao1;
    }
    ~VanDongVien()
    {
        this->hoten = "";
        this->tuoi = 0;
        this->monthidau = "";
        this->cannang = 0.0;
        this->chieucao = 0.0;
    }
    friend istream &operator >>(istream &is, VanDongVien &vdv)
    {
        cin.ignore();
        cout << "Nhap Ho Ten: "; fflush(stdin); getline(is, vdv.hoten);
        cout << "Nhap Mon Thi Dau: "; fflush(stdin); getline(is, vdv.monthidau);
        cout << "Nhap Tuoi: "; is >> vdv.tuoi;
        cout << "Nhap Can Nang: "; is >> vdv.cannang;
        cout << "Nhap Chieu Cao: "; is >> vdv.chieucao;
        return is;
    }
    friend ostream &operator <<(ostream &os, VanDongVien &vdv)
    {
        cout << "Ho Ten: " << vdv.hoten << endl;
        cout << "Mon Thi Dau: " << vdv.monthidau << endl;
        cout << "Tuoi: " << vdv.tuoi << endl;
        cout << "Can Nang: " << vdv.cannang << endl;
        cout << "Chieu cao: " << vdv.chieucao << endl;
        return os;
    }

    bool operator > (const VanDongVien &vdv)
    {
        if (this->chieucao > vdv.chieucao)
            return true;
        else if (this->chieucao < vdv.chieucao)
            return false;
        else if (this->cannang > vdv.cannang)
            return true;
        else
            return false;
    }
};


void swap(VanDongVien &a, VanDongVien &b)
{
    VanDongVien temp;
    temp = a;
    a = b;
    b = temp;
}

void BubbleSort(VanDongVien arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

int main(int argc, char const *argv[])
{
    VanDongVien p("Nguyen Van A", 20, "Bong Da", 178, 70.5);
    cout << p;

    int n;
    cout << "\nNhap so luong van dong vien: "; cin >> n;
    VanDongVien *arr = new VanDongVien[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; ++i)
    {
        cout << arr[i];
    }

    cout << "\n------Tien hanh Sort---------" << endl;
    BubbleSort(arr, n);
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i];
    }

    return 0;
}
