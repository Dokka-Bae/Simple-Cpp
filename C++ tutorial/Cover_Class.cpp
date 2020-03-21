// Cach su dung cac phuong thuc cua lop thanh phan

#include <iostream>
using namespace std;

class DIEM
{
    private:
        int x, y;
    public:
        DIEM()
        {
            x = y = 0;
        }
        DIEM(int x1, int y1)
        {
            x = x1; y = y1;
        }
        void in()
        {
            cout << "(" << x << " , " << y << ")";
        }
};

class DT                                        // class DIEM la class thanh phan cua DT
{
    private:
        DIEM d1, d2;
        int m;
    public:
        /* Dung ham tao cua lop thanh phan de xay dung ham tao cua lop bao */
        DT() : d1(), d2()
        {
            m = 0;
        }
        DT(int m1, int x1, int y1, int x2, int y2) : d1(x1, y1) , d2(x2, y2)
        {
            m = m1;
        }
        /* Xay dung ham tao thong thuong cua lop bao */
        DT(int m1, DIEM t1, DIEM t2)
        {
            m = m1;
            d1 = t1;                            // o day co the su dung toan tu gan (operation=)
            d2 = t2;
        }
        void in()
        {
            cout << "\nDiem dau: "; d1.in();
            cout << "\nDiem cuoi:"; d2.in();
            cout << "\nMau: " << m;
        }
};

int main(int argc, char const *argv[])
{
    /* code */
    DT u, v(1, 100, 200, 300, 400),
    s(2, DIEM(500, 500), DIEM(600,600));

    u.in();
    v.in();
    s.in();

    return 0;
}
