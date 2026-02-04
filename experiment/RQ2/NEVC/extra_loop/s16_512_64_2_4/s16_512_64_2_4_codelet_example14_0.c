#include <stdio.h>

extern int in[][64];
extern int coeff[][64];
extern int *out;
extern int k;
extern int j;
extern int i;

void loop(){
for (k = 0; k < 2; k++) {
    int dot_product = 0;
    for (i = 0; i < 512; i++)
        for (j = 0; j < 64; j++)
            dot_product += in[i + k][j] * coeff[i][j];
    out[k] = dot_product;
}

}
