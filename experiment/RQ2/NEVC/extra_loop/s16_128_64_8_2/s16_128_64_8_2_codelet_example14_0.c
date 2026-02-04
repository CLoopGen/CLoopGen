#include <stdio.h>

extern int in[][64];
extern int coeff[][64];
extern int *result;
extern int k;
extern int j;
extern int i;

void loop(){
for (k = 0; k < 8; k++) {
    int sum = 0;
    for (i = 0; i < 128; i++)
        for (j = 0; j < 64; j++)
            sum += in[i + k][j] * coeff[i][j];
    result[k] = sum;
}

}
