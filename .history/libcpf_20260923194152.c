#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "libcpf.h"

/* Array com os 11 digitos do CPF:
   posicoes 0-8  -> digitos base (gerados aleatoriamente)
   posicao  9    -> 1o digito verificador
   posicao  10   -> 2o digito verificador */
int cpf[11];

/* Calcula um digito verificador a partir da soma ponderada 's'
   Regra do modulo 11:
   - resto = s % 11
   - se resto < 2, DV = 0
   - senao, DV = 11 - resto */
int calcula_dv(int s){
    int resto = s % 11;

    if(resto < 2){
        return 0;
    }

    return 11 - resto;
}

/* Calcula os dois digitos verificadores a partir dos 9 digitos
   base ja armazenados em cpf[] e imprime o CPF completo. */
void calcula_cpf(){
    int soma;
    int peso;
    int i;

    /* 1o digito verificador: pesos de 10 a 2 sobre os 9 primeiros digitos */
    soma = 0;
    peso = 10;
    for(i = 0; i < 9; i++){
        soma += cpf[i] * peso;
        peso--;
    }
    cpf[9] = calcula_dv(soma);

    /* 2o digito verificador: pesos de 11 a 2 sobre os 10 primeiros digitos
       (os 9 digitos base + o 1o DV que acabamos de calcular) */
    soma = 0;
    peso = 11;
    for(i = 0; i < 10; i++){
        soma += cpf[i] * peso;
        peso--;
    }
    cpf[10] = calcula_dv(soma);

    printf("CPF gerado: %d%d%d.%d%d%d.%d%d%d-%d%d\n",
           cpf[0], cpf[1], cpf[2],
           cpf[3], cpf[4], cpf[5],
           cpf[6], cpf[7], cpf[8],
           cpf[9], cpf[10]);
}

/* Gera os 9 digitos base aleatoriamente e manda calcular os
   digitos verificadores + imprimir o CPF. */
void gera_cpf(){
    int i;

    srand(time(NULL));

    for(i = 0; i < 9; i++){
        cpf[i] = rand() % 10;
    }

    calcula_cpf();
}