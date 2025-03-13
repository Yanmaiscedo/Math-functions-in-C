#include <stdio.h>

int Fatorial(int *n);
double NumeroHarmonico(int *n);
double calcularS();
double calcularE(int *N);
double RaizQuadrada(double *x);
double Cosseno(double x, int numTermos, double *resultado);
double Seno(double x);

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
    int opcao;
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
    {
        int numero, *ptrnumero = &numero;
        printf("Digite um número inteiro positivo: ");
        scanf("%d", &numero);
        int resultado = Fatorial(numero);
        printf("%d! = %llu\n", numero, resultado);
        break;
    }
    case 2:
    {

        int n, *ptrn = &n;
        printf("Digite o valor de n: ");
        scanf("%d", &n);
        double resultado = NumeroHarmonico(n);
        printf("H%d = %.6lf\n", n, resultado);
        break;
    }
    case 3:
    {
        double resultado = calcularS();
        printf("O valor de S é: %.6lf\n", resultado);
        break;
    }
    case 4:
    {
        int N, *prtN = &N;
        printf("Digite um valor inteiro e positivo N: ");
        scanf("%d", &N);
        double resultado = calcularE(N);
        printf("O valor de E para N = %d é: %.6f\n", N, resultado);
        break;
    }
    case 5:
    {
        double numero, raiz, *ptrnumero = &numero;
        printf("Digite um número positivo: ");
        scanf("%lf", &numero);
        while (numero < 0)
        {
            printf("Valor inválido! Digite um número positivo: ");
            scanf("%lf", &numero);
        }
        raiz = RaizQuadrada(&numero);
        printf("A raiz quadrada de %.4lf é %.4lf\n", numero, raiz);
        break;
    }
    case 6:
    {
        double valorX, resultado, *ptrvalorX = &valorX, *ptresultado = &resultado;
        int numTermos, *ptrnumTermos = &numTermos;
        printf("Digite o valor de x: ");
        scanf("%lf", &valorX);
        printf("Digite o número de termos para o somatório (máximo 25): ");
        scanf("%d", &numTermos);
        Cosseno(valorX, numTermos, &resultado);
        printf("Cosseno(%.2lf) = %.5lf\n", valorX, resultado);
        break;
    }
    case 7:
    {
        double valor, *ptr = &valor;
        printf("Digite o valor de x: ");
        scanf("%lf", &valor);
        printf("O seno(%.2lf) = %.5lf\n", valor, Seno(valor));
        break;
    }
    case 8:
    {
        printf(" 1- A funçõa calcula fatorial de um numero quee o produto de todos os inteiros\n positivos menores ou iguais a esse numero. E denotado pelo simbolo /!\n, por exemplo, o fatorial de 5 e representado como 5!.\n 2- A funçao calcula o numero harmonico designado por Hn, onde Hn=1+1/2+1/3+1/4...1/n\n 3- A função calcula e escrever o valor de S tal que: s=1/1+3/2+5/3+7/4+...+99/50\n 4- A função calcula e le um valor inteiro e positivo N e mostra o valor de E, conforme \na fórmula a seguir:  E=1/1!+1/2!+1/3!+...+1/n!\n 5- A função calcula a raiz quadrada de x\n 6- A função calcula cosseno pelo polinômio de Mclaurin\n 7- A função calcula o seno definido pela seguinte série:  sen(x)=x^1/1!-x^3/3!+x^5/5!-x^7/7!+...");
        break;
    }
    case 0:
        printf("Encerrando o programa.\n");
        break;
    default:
        printf("Opção inválida. Tente novamente.\n");
    }

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

double Cosseno(double x, int numTermos, double *resultado)
{
    *resultado = 1.0;
    double termo = 1.0;
    for (int i = 1; i <= numTermos; i++)
    {
        termo *= (-x * x) / ((2 * i) * (2 * i - 1));
        *resultado += termo;
    }
}

double Seno(double x)
{
    double resultado = 0.0;
    double termo = x;
    for (int i = 1; i <= 25; i++)
    {
        resultado += termo;
        termo *= -(x * x) / ((2 * i) * (2 * i + 1));
    }
    return resultado;
}