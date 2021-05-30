#include <iostream>
#include <ostream>
#include <math.h>
#include <iomanip> 

using namespace std;

struct Complex {
    double real;
    double imag;
};

Complex operator + (Complex a, Complex b) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    Complex ans;
    ans.real = a.real + b.real;
    ans.imag = a.imag + b.imag;
    return ans;
}

Complex operator - (Complex a, Complex b) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    Complex ans;
    ans.real = a.real - b.real;
    ans.imag = a.imag - b.imag;
    return ans;
}

Complex operator * (Complex a, Complex b) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    Complex ans;
    ans.real = a.real * b.real - a.imag * b.imag;
    ans.imag = a.real * b.imag + a.imag * b.real;
    return ans;
}

Complex operator / (Complex a, Complex b) {
    /*****************
    # YOUR CODE HERE #
    (a1+a2i)/(b1+b2i) = (a1+a2i)(b1-b2i)/(b1^2+b2^2) = (a1b1+a2b2-a1b2*i+a2b1*i)
    *****************/
    Complex ans;
    ans.real = (a.real*b.real + a.imag*b.imag)/(pow(b.real,2)+pow(b.imag,2));
    ans.imag = (-a.real*b.imag + a.imag*b.real)/(pow(b.real,2)+pow(b.imag,2));
	return ans;
}	
ostream& operator << (ostream& out, const Complex &a) {
    out << '(' << std::setprecision(2) << a.real << (a.imag >= 0 ? '+' : '-') << std::setprecision(2) << fabs(a.imag) << 'i' << ')';
    return out;
}

int main() {
    double real_a, real_b, img_a, img_b;
    cin >> real_a >> img_a;
    cin >> real_b >> img_b;
    
    Complex a{real_a, img_a};
    Complex b{real_b, img_b};
    
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;
    
    return 0;
}
