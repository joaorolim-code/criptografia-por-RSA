#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool primo(int num)
{
    if(num <= 1){
        printf("O numero nao eh primo\n");
        return false;
    }
    if(num == 2){
        return true;
    }
    if(num%2==0){
        printf("O numero nao eh primo\n");
        return false;
    }
    for(int i = 3; i*i<=num; i+=2){
        if(num%i==0){
            printf("O numero nao eh primo\n");
            return false;
        }
    }
    return true;
}

bool numval(int num)
{
    if(num <= 0){
        printf("O numero nao eh valido\n");
        return false;
    }
    return true;
}

bool coprimo(int num_maior, int num_menor)
{
    int a = num_maior;
    int b = num_menor;
    while(b != 0){
        int aux = b;
        b = a % b;
        a = aux;
    }
    return (a == 1);
}

int chave_privada(int num_maior, int num_menor)
{
    for(long long d = 1; d<=num_maior; d++){
        if((num_menor*d) % num_maior == 1){
            printf("Chave privada: %lld\n", d);
            return d;
        }
    }
    printf("Nao foi possivel calcular a chave privada\n");
    return -1;
}

void criptografar(int mensagem, int chave_publica, int modulo)
{
    if(mensagem >= modulo){
        printf("Mensagem maior que o modulo\n");
        return;
    }
    int cont = 0;
    long long c = 1;
    while(cont < chave_publica){
        c = (c * mensagem) % modulo;
        cont++;
    }
    printf("Mensagem criptografada: %lld\n", c);
}

int main()
{
    int p = 0, q = 0;
    int mult = 1;
    int tot = 1;
    int exp = 0;
    int cript = 0;
    printf("escolha dois numeros primos distintos:\n");
    scanf("%d", &p);
    if(primo(p) == false || numval(p) == false){
        printf("O primeiro numero nao eh valido, tente novamente\n");
        return -1;
    }
    scanf("%d", &q);
    if(primo(q) == false || numval(q) == false){
        printf("O segundo numero nao eh valido, tente novamente\n");
        return -1;
    }
    printf("Calculando o modulo...\n");
    mult = p*q;
    printf("Calculando a funcao totiente...\n");
    tot = (p-1)*(q-1);
    printf("Totiente: %d\n", tot);
    printf("Escolha o expoente da operacao,\n ele precisa ser maior que 1 e menor que o totiente calculado,\nalem de ser coprimo do mesmo:\n");
    scanf("%d", &exp);
    if(coprimo(tot, exp) == false){
        printf("O expoente informado nao eh valido, tente novamente\n");
        return -1;
    }
    printf("Calculando a sua chave privada...\n");
    int res = chave_privada(tot, exp);
    if(res == -1){
        printf("Nao foi possivel calcular a chave privada, tente novamente\n");
        return -1;
    }
    printf("digite o numero a ser criptografado:\n");
    scanf("%d", &cript);
    criptografar(cript, exp, mult);
    system("pause");
    return 0;
} 