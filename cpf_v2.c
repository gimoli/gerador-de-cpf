#include <stdio.h>
int calcula_dv(int s) {
    int r = s % 11;
    int dv;
    if (r < 2) {
        dv = 0;
    }
    else {
        dv = 11 - r;
    }
    return dv;
}
int main(){
    int soma1=0,soma2=0,dv1,dv2;
    int n;
    int j = 10;

    for (int i=1; i<=9; i++) {
        printf("Digite o num %d do CPF:",i);
        scanf("%d",&n);  
        soma1 = soma1 + (n * j);        
        if (i>1) {
            if (j!=2) {
                soma2 = soma2 + (n * (j+1));
            }
            else {
                dv1 = calcula_dv(soma1);
                soma2 = soma2 + (dv1 * (j+1));
                dv2 = calcula_dv(soma2);
            }
        }
        j = j - 1;
    }
    printf("O dv1 do CPF eh: %d\n", dv1);
    printf("O dv2 do CPF eh: %d\n", dv2);
    return 0;
}