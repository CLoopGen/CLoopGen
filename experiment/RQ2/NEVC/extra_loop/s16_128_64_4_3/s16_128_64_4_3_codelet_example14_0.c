#include <stdio.h>

extern int A[][64];
extern int coeff[][64];
extern int *out;
extern int k;
extern int j;
extern int i;

void loop(){
for (k = 0; k < 4; k++) {
    int sum = 0;
    for (i = 0; i < 128; i++)
        for (j = 0; j < 64; j++)
            sum += A[i + k][j] * coeff[i][j];
    out[k] = sum;
}

}
