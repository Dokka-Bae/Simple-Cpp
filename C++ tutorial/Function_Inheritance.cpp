#include <iostream>
using namespace std;

class DIEM
{
    private:
        double x, y;
    public:
        DIEM()
        {
            x = y = 0.0;
        }
        DIEM(double x1, double y1)
        {
            this->x = x1;
            this->y = y1;
        }
        void in()
        {
            cout << "\nx = " << x << " y = " << y;
        }
};

class HINH_TRON : public DIEM
{
    private:
        double r;
    public:
        HINH_TRON()
        {
            r = 0.0;
        }
        HINH_TRON(double x1, double y1, double r1) : DIEM(x1, y1)
        {
            this->r = r1;
        }
        double getR()
        {
            return r;
        }
};

int main(int argc, char const *argv[])
{
    HINH_TRON h(2.5, 3.5, 8);

    cout << "\nHinh tron co tam: ";
    h.in();
    cout << "\nCo ban kinh: " << h.getR();

    return 0;
}
