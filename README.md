# Trabalho-soma-de-riemman
Trabalho da cadeira de Cálculo II, do professor Renan Santos

-------------------------------------------------------------

O programa compila uma elaborada soma de riemman para os 5 tipos de integrais, sendo respectivamente:
- polinomial
- trigonométrica
- exponencial
- logaritimica
- raiz enésima

Com isso, as funções referentes a cada uma delas acompanham a primeira letra de seu nome(p,t,e,l,r), após o título atrelado ao calculo do resultado tanto da função quanto da soma de riemann. Ex: funcaop ou riemanne (respectivamente para função polinomial e soma de riemann da funcao exponencial)

O programa possui uma função individual para cada etapa de calculo, para cada possivel função.

-----------------------------------------------------------

## Funcionamento
> Para começar, vamos destrinchar as variaveis usadas:
* __a e b__: são os limites inferiores e superiores da integral
* __n__: é o número de repartiçoes da soma, quão maior, mais exato será o cálculo
* __x__: sempre será o x de qualquer função, variando conforme os limites estabelecidos
* __resp__: valor que em todas as funções armazenam a soma das respostas
* __dx e xi__: são respectivamente a largura de cada retângulo(delta x), e a altura de x no momento atual, varia com a função

> Algumas mais específicas:
* __gr__: aparece apenas na função polinomial, e representa o grau da função, é usado para quantificar os termos presentes
* __A[ ]__: aparece apenas na função polinomial, e representa uma lista com os coeficientes em uma ordem crescente, portanto o primeiro termo que aparece, é o termo independente, subindo o grau da equação dependendo o grau(gr)
* __base__: aparece nas funções exponencial e logaritimica, e são respectivamente a base do expoente x, e a base do log de x
* __enesimo__: aparece apenas na função da raiz enésima, e representa esse valor n, "enésimo" valor.


---------------------------------------------------------

## Sistema primário e suas funcionalidades
> _main(1).cpp_

O funcionamento do sistema tenta aproximar-se a uma simples integral resolvida por soma de riemann. É usado um sistema de loops simples que permitem que o código seja aproximadamente linear (O(n)).

Em relação a o uso trigonométrico, a função funcaot pode ser adaptada para outras funções trigonométricas, como sen(x), ou tg(x). Por padrão foi escrita em cos(x):
```cpp
double funcaot(double x){ //função feita para calcular o valor de uma função trigonometrica
    return cos(x); //possível alteração de função!
}
```
Para usar o sistema, você pode ou usar o primeiro arquivo e tratar do código puro, chamando funções individualmente, com o padrão de chamada sendo:
* __riemannp(número n de repartições, limite inferior(a), limite superior(b), lista (P ou A) de coeficientes, grau do polinomio)__
* __riemannt(número n de repartições, limite inferior(a), limite superior(b),__
* __riemanne(número n de repartições, base do expoente x,limite inferior(a), limite superior(b),__
* __riemannl(número n de repartições, base do logaritimo de x,limite inferior(a), limite superior(b),__
* __riemannr(número n de repartições, número n da raiz enésima, limite inferior(a), limite superior(b),__

> O sistema vem com alguns exemplos já escritos, porém podem ser facilmente mudados com as informações desse read me;

Com esse chamado, a função precisa de uma variavel para imprimir o resultado em seguida. Segue exemplo:
```cpp
double P[3]={4, 4, 1}; // representa a equação polinomial x^2+4x+4
    double z= riemannp(10000, 0, 2, P, 2); // 10000 repartições, do limite inferior 0 até o superior 2, da lista P[ ], de grau 2
    cout << z<< endl;
```

Ou entrar no segundo, com um sistema mais interativo e direcionado.
> Algo extra que tomei interesse, para deixar o sistema mais 'user friendly'

----------------------------------------------------------

## Programa secundário
> _main(2).cpp_

O uso do programa secundário é concerteza mais simples e didático, mas trago alguns detalhes também...
* O máximo do expoente polinomial é uma sugestão, visto que depende de máquina a máquina
* Novamente, a função trigonométrica pode ser alterada, mas o menu não atualizaria
* Os casos de 'ERRO' seguem as regras matemáticas padrão
* Se possível não digitar nada além de números, há risco de bugs
* Pode usar M_PI e M_E como pi e número de Euler
* Criado com intuito de facilitar o uso, aporveite!
