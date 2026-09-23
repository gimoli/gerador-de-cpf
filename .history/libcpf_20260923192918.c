#include "libcpf.h"
#include <string.h>

int validar_cpf(const char*cpf){
    if(strlen(cpf)!=11){
        return 0;
    }

for(int i=0;i<11;i++) {if(cpf[i] <'0'||cpf[i]>'9')
return 0;
num[i] = cpf[i]-'0';
}

}