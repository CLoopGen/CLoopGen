#include <stdio.h>

extern int in[][1024];
extern int coeff[][1024];
extern int *result;
extern int k;
extern int j;
extern int i;

void loop(){
for (k = 0; k < 2; k++) {
    int sum = 0;
    for (i = 0; i < 512; i++)
        for (j = 0; j < 1024; j++)
            sum += in[i + k][j] * coeff[i][j];
    result[k] = sum;
}

}
