#include "libcpf.h"
#include <string.h>

void gerar_cpf(char*cpf_gerado){
int num;
    for(int i=0; i<9; i++){
        num = rand() % 10;}
        cpf_gerado[i] = num + '0';
    }
    cpf_gerado[9] = '\0';
}