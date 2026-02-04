#include <stdio.h>

extern int in[][8192];
extern int coeff[][8192];
extern int *out;
extern int k;
extern int j;
extern int i;

void loop(){
for (k = 0; k < 8; k++) {
    int sum = 0;
    for (i = 0; i < 128; i++)
        for (j = 0; j < 8192; j++)
            sum += in[i + k][j] * coeff[i][j];
    out[k] = sum;
}

}
