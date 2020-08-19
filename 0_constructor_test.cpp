#include <iostream>
using namespace std;

class Complex{
    private:
        double real, imag;
    public:
        Complex(double r);
        Complex(double r, double i);
        Complex(Complex c1, Complex c2);
        friend ostream & operator<<(ostream & os, const Complex & c);
};
Complex::Complex(double r):real(r),imag(0){}
Complex::Complex(double r, double i): real(r), imag(i){
    cout << "invoke constructor r i" << endl;
}
Complex::Complex(Complex c1, Complex c2): real(c1.real + c2.real), imag(c1.imag + c2.imag){}
ostream & operator<<(ostream & os, const Complex & c){
    os << c.real << "+" << c.imag << "i";
    return os;
}

int main(){
    Complex c1(1,2);
    cout << "c1: " << c1 << endl;

    Complex c2 = Complex(1,2);
    cout << "c2: " << c2 << endl;

    Complex c3 = (1,2); // 2+0i
    cout << "c3: " << c3 << endl;


    system ("pause");
    return 0;
}