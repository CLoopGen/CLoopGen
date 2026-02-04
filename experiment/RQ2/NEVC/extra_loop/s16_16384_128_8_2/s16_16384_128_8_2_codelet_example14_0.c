#include <stdio.h>

extern int in[][128];
extern int coeff[][128];
extern int *result;
extern int k;
extern int j;
extern int i;

void loop(){
for (k = 0; k < 8; k++) {
    int sum = 0;
    for (i = 0; i < 16384; i++)
        for (j = 0; j < 128; j++)
            sum += in[i + k][j] * coeff[i][j];
    result[k] = sum;
}

}
