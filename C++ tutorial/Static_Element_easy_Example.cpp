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
        static void in()
        {
            cout << "\nTong so hoa don: " << tshd;
            cout << "\nTong so tien ban: " << tstienban;
        }
};

int HDBH::tshd = 5;
double HDBH::tstienban = 200;

int main(int argc, char const *argv[])
{
    HDBH::in();
    return 0;
}
