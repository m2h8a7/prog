#include <iostream>
#include <cmath>

using namespace std;

class Complex {
private:
    int Im;
    int Re;
public:
    Complex() {}
    Complex(int r, int i) {
        Im = i;
        Re = r;
    }
    Complex(const Complex& c) {
        Im = c.getIm();
        Re = c.getRe();
    }
    int getIm() const { return Im; }
    int getRe() const { return Re; }
    void setIm(int i) {
        Im = i;
    }
    void setRe(int r) {
        Re = r;
    }
    double getHossz() {
        return sqrt(pow(Re,2)+pow(Im,2));
    }
    Complex operator+(Complex c) const
    {
        return Complex(*this.Re+c.getRe(),Im+c.getIm());
    }
    Complex operator*(Complex c) const
    {
        //(a+bi)*(c+di) = a*c-b*d+i(b*c+d*a)
        return Complex(Re*c.getRe()-Im*c.getIm(),
                       Im*c.getRe()+Re*c.getIm());
    }

    friend ostream& operator<<(ostream& out, const Complex& c);
    friend istream& operator>>(istream& in, Complex& c);
};

ostream& operator<<(ostream& out, const Complex& c)
{
    out << c.Re << "+" << c.Im << "i";
    return out;
}

istream& operator>>(istream& in, Complex& c)
{
    in >> c.Re >> c.Im;
    return in;
}

int main()
{
    Complex c(5,10);
    //operator<<(cout,c)
    //c.operator<<(cout)
    cout << c << endl;
    //std::cout << c.getRe() << "+" << c.getIm() << "i" << endl;
    c.setRe(5);
    c.setIm(10);
    cout << c.getHossz() << endl;
    //c = 5+10i
    Complex c1(6,-3);
    //c1 = 6-3i;
    //operator+(c,c1)
    //c.operator+(c1)
    //c1.operator+(c)
    //Complex res = c*c1; //copy constructor
    Complex res;
    //res = c*c1; //értékadó operátor
    cin >> res;
    cout << res << endl;
    return 0;
}
