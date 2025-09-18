#include <iostream>
#include <cmath>
using namespace std;
double funcaop(double x, double A[], int gr){
    double y=0;
    for(int i=0; i<=gr; i++){
        y+=pow(x, i)* A[i];
    }
    return y;
}
double funcaot(double x){
    return sin(x);
}
double funcaoe(double base, double x){
    return pow(base ,x);
}
double funcaol(double x){
    return log(x);
}
double funcaor(double enesimo, double x){
    return pow(1/enesimo, x);
}
double riemannp(int n, double a, double b, double A[], int gr){
    double resp=0;
    double dx=(b-a)/static_cast<double>(n);
    for(int i=0; i<n; i++){
        double xi= a + i * dx;
        resp+=funcaop(xi, A, gr)*dx;
    }
    return resp;
}
double riemannt(int n, double a, double b) {
    double resp=0;
    double dx=(b-a)/static_cast<double>(n);
    for (int i = 0; i < n; i++) {
        double xi = a + i * dx;
        resp += funcaot(xi)*dx;
    }
    return resp;
}
double riemanne(int n, double base, double a, double b) {
    double resp=0;
    double dx=(b-a)/static_cast<double>(n);
    for (int i = 0; i < n; i++) {
        double xi = a + i * dx;
        resp += funcaoe(b ,xi)*dx;
    }
    return resp;
}
double riemannl(int n, double a, double b) {
    double resp=0;
    double dx=(b-a)/static_cast<double>(n);
    for (int i = 0; i < n; i++) {
        double xi = a + i * dx;
        resp += funcaol(xi)*dx;
    }
    return resp;
}
double riemannr(int n, double enesimo, double a, double b) {
    double resp=0;
    double dx=(b-a)/static_cast<double>(n);
    for (int i = 0; i < n; i++) {
        double xi = a + i * dx;
        resp += funcaor(enesimo, xi);
    }
    return resp;
}
int main()
{
    double P[3]={4, 2, 1};
    double z= riemannp(10000, 0, 2, P, 2);
    cout << z<< endl;
    z=riemannt(10000, 0, M_PI);
    cout << z<< endl;
    z=riemanne(10000, 2, 0, 3);
    cout << z<< endl;
    z=riemannl(20000, 1, M_E);
    cout << z<< endl;
    z=riemannr(10000, 4, 0, 3);
    cout << z<< endl;
    return 0;
}