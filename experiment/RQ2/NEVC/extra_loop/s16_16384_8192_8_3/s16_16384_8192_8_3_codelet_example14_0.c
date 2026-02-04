#include <stdio.h>

extern int A[][8192];
extern int coeff[][8192];
extern int *out;
extern int k;
extern int j;
extern int i;

void loop(){
for (k = 0; k < 8; k++) {
    int sum = 0;
    for (i = 0; i < 16384; i++)
        for (j = 0; j < 8192; j++)
            sum += A[i + k][j] * coeff[i][j];
    out[k] = sum;
}

}
