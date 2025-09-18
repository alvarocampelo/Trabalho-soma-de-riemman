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

## Sistema e suas funcionalidades

O funcionamento do sistema tenta aproximar-se a uma simples integral resolvida por soma de riemann. É usado um sistema de loops simples que permitem que o código seja aproximadamente linear (O(n)).

Em relação a o uso trigonométrico, a função funcaot pode ser adaptada para outras funções trigonométricas, como sen(x), ou tg(x). Por padrão foi escrita em cos(x)

