#include <iostream>
#include <cmath>
#include <limits>
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
void menu(){
    double a, b, resp;
    int n;
    cout << R"(
    +====================================================+
    |                                                    |
    |   OUTPUT:                                          |
    |                                                    |
    |                b                                   |
    |                ∫ f(x)dx = [RESULTADO]              |
    |                a                                   |
    |                                                    |
    |                                                    |
    |   > Calculadora de Integrais Definidas_            |
    +====================================================+)" << endl << "Aperte enter para continuar";
    cin.get();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int escolha;
    do {
        cout << R"(
        +====================================================+
        |      CALCULADORA DE INTEGRAIS (SOMA DE RIEMANN)    |
        +====================================================+
        | Escolha o tipo de funcao para integrar:            |
        |                                                    |
        | 1. Polinomial                                      |
        | 2. Trigonometrica (cos(x))                         |
        | 3. Exponencial                                     |
        | 4. Logaritmica                                     |
        | 5. Raiz Enesima                                    |
        |                                                    |
        | 6. Sair                                            |
        +----------------------------------------------------+
        )" << endl << "Sua escolha: ";
        cin >> escolha;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Qual o n(número de repartições dx) você quer?"<< endl << "Escolha de 1 a 50000"<< endl;
        cin>>n;
        if (escolha == 1) {
            int g;
            const int graum = 10;
            double P[graum + 1];

            cout << "--- Integral Polinomial ---" << endl;
            cout << "Digite o grau do polinomio (o maximo é " << graum << "): ";
            cin >> g;
            
            if (g > graum) {
                cout << "ERRO"<< endl;
            } else {
                cout << "Digite os coeficientes, do termo x^0 ate x^ " << g << ":" << endl;
                for (int i = 0; i <= g; ++i) {
                    cout << "Coeficiente " << i << ": ";
                    cin >> P[i];
                }

                cout << "Digite o limite inferior (a): ";
                cin >> a;
                cout << "Digite o limite superior (b): ";
                cin >> b;

                resp = riemannp(n, a, b, P, g);
                cout << "Resultado da integral: " << resp << endl;
            }
            escolha=6;
        } else if (escolha == 2) {
            cout << "--- Integral Trigonometrica ---" << endl;
            cout << "Digite o limite inferior (a): ";
            cin >> a;
            cout << "Digite o limite superior (b): ";
            cin >> b;
            resp = riemannt(n, a, b);
            cout << "Resultado: " << resp << endl;
            escolha=6;
        } else if (escolha == 3) {
            double base;
            cout << "--- Integral Exponencial ---" << endl;
            cout << "Digite a base da funcao: ";
            cin >> base;
            cout << "Digite o limite inferior (a): ";
            cin >> a;
            cout << "Digite o limite superior (b): ";
            cin >> b;
            resp = riemanne(n, base, a, b);
            cout << "Resultado: " << resp << endl;
            escolha=6;
        } else if (escolha == 4) {
            double base;
            cout << "--- Integral Logaritmica ---" << endl;
            cout << "Digite a base do logaritmo: ";
            cin >> base;
            cout << "Digite o limite inferior (a): ";
            cin >> a;
            cout << "Digite o limite superior (b): ";
            cin >> b;
            if (a <= 0 || base <= 0 || base == 1) {
                cout << "ERRO" << endl;
            } else {
                resp = riemannl(n, base, a, b);
                cout << "Resultado da integral: " << resp << endl;
            }
            escolha=6;
        } else if (escolha == 5) {
            double enesimo;
            cout << "--- Integral de Raiz Enesima ---" << endl;
            cout << "Digite o indice da raiz: ";
            cin >> enesimo;
            cout << "Digite o limite inferior (a): ";
            cin >> a;
            cout << "Digite o limite superior (b): ";
            cin >> b;
             if (a < 0) {
                cout << "ERRO" << endl;
            } else {
                resp = riemannr(n, enesimo, a, b);
                cout << "Resultado: " << resp << endl;
            }
            escolha=6;
        } else if (escolha == 6) {
            cout << "FIM." << endl;
        } else {
            cout << "ERRO" << endl;
        }
    }
    while(escolha!=6);
}
int main()
{
    menu();
    return 0;
}
