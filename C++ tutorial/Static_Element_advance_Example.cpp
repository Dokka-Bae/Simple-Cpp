/* Xet bai toan quan ly hoa don ban hang. Moi hoa don co 2 du lieu la ten hang va tien ban.
Su dung ham toa de tao ra cac hoa don, dùng hàm hủy để bỏ đi các hóa đơn không cần lưu trữ,
dùng một phương thức để sửa chữa nội dung hóa đơn (nhập lại tiền bán). Vấn đề đặt ra là sau
một số thao tác: Tạo, sửa và hủy hóa đơn thì tổng số hoá đơn còn lại là bao nhiêu và tổng
số tiền trên các hóa đơn còn lại là bao nhiêu */

#include <iostream>
using namespace std;

class HDBH
{
    private:
        char *tenhang;                      // Ten hang
        double tienban;                     // Tien ban
        static int tshd;                    // Tong so hoa don
        static double tstienban;            // Tong so tien ban
    public:
        HDBH(char *tenhang1 = NULL, double tienban1 = 0.0)
        {
            tenhang = tenhang1;
            tienban = tienban1;
            ++tshd;
            tstienban += tienban;
        }
        ~HDBH()
        {
            --tshd;
            tstienban -= tienban;
        }

        void sua();
        static void in();
};

int HDBH::tshd = 0;
double HDBH::tstienban = 0.0;

void HDBH::in()
{
    cout << "\nTổng số hóa đơn lúc này: " << tshd;
    cout << "\nTổng số tiền bán lúc này: " << tstienban;
}

void HDBH::sua()
{
    cout << "\nTên hàng: " << tenhang;
    cout << "\nTiền bán: " << tienban;
    tstienban -= tienban;
    cout << "\nSửa tiền bán: "; cin >> tienban;
    tstienban += tienban;
}

int main(int argc, char const *argv[])
{
    HDBH *h1 = new HDBH("Xi măng", 2000);
    HDBH *h2 = new HDBH("Sắt thép", 3000);
    HDBH *h3 = new HDBH("Ti vi", 4000);
    HDBH::in();

    delete h1; HDBH::in();
    h2 -> sua(); HDBH::in();
    delete h3; HDBH::in();

    return 0;
}
