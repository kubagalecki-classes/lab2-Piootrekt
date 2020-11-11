#include <iostream>
using namespace std;

class Wektor
{
public:
    Wektor(int n)
    {
        x = new double[n];
        for (int i = 0; i < n; i++) {
            x[i] = 0;
        }
        dlug = n;
        poj  = n;
    }

    ~Wektor()
    {
        delete[] x;
        cout << "~" << endl;
    }

    double* point() { return x; }

    int getd() { return dlug; }

    int getp() { return poj; }

    void print()
    {
        for (int i = 0; i < dlug; i++) {
            cout << x[i] << endl;
        }
    }

    void zmienDlugosc(int newn)
    {
        if (newn <= poj) {
            for (int i = newn; i < poj; i++) {
                x[i] = 0;
            }
            dlug = newn;
        }
        else {
            double* temp = new double[newn];
            for (int i = 0; i < dlug; i++) {
                temp[i] = x[i];
            }
            delete[] x;
            x = temp;

            dlug = newn;
            poj  = newn;
            for (int i = 0; i < poj; i++) {
                x[i] = 0;
            }
        }
    }

private:
    double* x;
    int     dlug;
    int     poj;
};

int main()
{
    Wektor w1{10};
}

//double& operator[](unsigned int) zwracajacy referencje do tablicy otrzymanej z tego indeksu 
