#include <iostream>
#include <cmath>
using namespace std;
double funcaop(double x, double A[], int gr){ //função feita para calcular o valor de uma equação polinomial
    double y=0;
    for(int i=0; i<=gr; i++){
        y+=pow(x, i)* A[i];
    }
    return y;
}
double funcaot(double x){ //função feita para calcular o valor de uma função trigonometrica
    return cos(x); //possível alteração de função!
}
double funcaoe(double base, double x){ //função feita para calcular o valor de uma função exponencial
    return pow(base ,x);
}
double funcaol(double base, double x){ //função feita para calcular o valor de uma função logaritimica
    return log(x)/log(base);
}
double funcaor(double enesimo, double x){ //função feita para calcular o valor de uma função de raiz enésima
    return pow(x, 1/enesimo);
}
double riemannp(int n, double a, double b, double A[], int gr){ //função da soma de riemann direcionada a polinomios
    double resp=0;
    double dx=(b-a)/static_cast<double>(n);
    for(int i=0; i<n; i++){
        double xi= a + i * dx;
        resp+=funcaop(xi, A, gr)*dx;
    }
    return resp;
}
double riemannt(int n, double a, double b) {  //função da soma de riemann direcionada a funções trigonométricas
    double resp=0;
    double dx=(b-a)/static_cast<double>(n);
    for (int i = 0; i < n; i++) {
        double xi = a + i * dx;
        resp += funcaot(xi)*dx;
    }
    return resp;
}
double riemanne(int n, double base, double a, double b) {  //função da soma de riemann direcionada a funções exponenciais
    double resp=0;
    double dx=(b-a)/static_cast<double>(n);
    for (int i = 0; i < n; i++) {
        double xi = a + i * dx;
        resp += funcaoe(base ,xi)*dx;
    }
    return resp;
}
double riemannl(int n, double base, double a, double b) {  //função da soma de riemann direcionada a funções logaritimicas
    double resp=0;
    double dx=(b-a)/static_cast<double>(n);
    for (int i = 0; i < n; i++) {
        double xi = a + i * dx;
        resp += funcaol(base, xi)*dx;
    }
    return resp;
}
double riemannr(int n, double enesimo, double a, double b) {  //função da soma de riemann direcionada a funções de raiz enésima
    double resp=0;
    double dx=(b-a)/static_cast<double>(n);
    for (int i = 0; i < n; i++) {
        double xi = a + i * dx;
        resp += funcaor(enesimo, xi)*dx;
    }
    return resp;
}
int main()
{
    double P[3]={4, 4, 1}; // x^2 + 4x + 4
    double z= riemannp(10000, 0, 2, P, 2); // integral de P, de 0 ate 2
    cout << z<< endl; // valor real = 18.667
    z=riemannt(30500, 0, M_PI);// integral de sen(x), de 0 até pi
    cout << z<< endl;// valor "real" = 0
    z=riemanne(10000, 2, 0, 4);// integral de 2^x, de 0 até 4
    cout << z<< endl; // valor "real" = 21.64
    z=riemannl(50000, 2, 1, 8); // integral de log2(x), de 1 até 8
    cout << z<< endl; // valor "real" = 13.90
    z=riemannr(10000, 4, 0, 16); // integral da raiz de indice 4, de 0 até 16
    cout << z<< endl; // valor real 25.6
}
