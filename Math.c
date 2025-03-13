#include <stdio.h>

int Fatorial(int *n);
double NumeroHarmonico(int *n);
double calcularS();
double calcularE(int *N);
double RaizQuadrada(double *x);

int main()
{
    printf("===============MENU===============\n");
    printf("----------O que procuras?---------\n");
    printf("1- O fatorial de um numero\n");
    printf("2- O numero hamonico designado por Hn\n");
    printf("3- O valor de S\n");
    printf("4- O valor de E\n");
    printf("5- A raiz de um numero\n");
    printf("6- A funcao para calcular cosseno pelo polinomio de Mclaurin\n");
    printf("7- A Funcao para calcular o seno de uma serie\n");
    printf("8- help (ajuda)\n");
    printf("0- Sair\n");
    printf("==================================\n");

    return 0;
}


int Fatorial(int *n)
{
    int fatorial = 1;
    for (int i = 1; i <= n; ++i)
    {
        fatorial *= i;
    }
    return fatorial;
}

double NumeroHarmonico(int *n)
{
    double resultado = 0.0;
    for (int i = 1; i <= n; i++)
    {
        resultado += 1.0 / i;
    }
    return resultado;
}

double calcularS()
{
    double soma = 0.0;
    int numerador = 1;
    int denominador = 1;
    for (int i = 1; i <= 50; i++)
    {
        soma += (double)numerador / denominador;
        numerador += 2;
        denominador++;
    }
    return soma;
}

double calcularE(int *N)
{
    double E = 0.0;
    double fatorial = 1.0;
    for (int i = 1; i <= N; ++i)
    {
        fatorial *= i;
        E += 1.0 / fatorial;
    }
    return E;
}

double RaizQuadrada(double *x)
{
    double raiz = *x;
    double erro = 0.0001;
    while (1)
    {
        double proximaRaiz = 0.5 * (raiz + (*x) / raiz);
        if (proximaRaiz - raiz < erro && raiz - proximaRaiz < erro)
        {
            break;
        }
        raiz = proximaRaiz;
    }
    return raiz;
}