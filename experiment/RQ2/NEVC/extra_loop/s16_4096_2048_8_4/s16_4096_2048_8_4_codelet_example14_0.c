#include <stdio.h>

extern int in[][2048];
extern int coeff[][2048];
extern int *out;
extern int k;
extern int j;
extern int i;

void loop(){
for (k = 0; k < 8; k++) {
    int dot_product = 0;
    for (i = 0; i < 4096; i++)
        for (j = 0; j < 2048; j++)
            dot_product += in[i + k][j] * coeff[i][j];
    out[k] = dot_product;
}

}
