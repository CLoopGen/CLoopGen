#include <stdio.h>

extern int in[][1024];
extern int coeff[][1024];
extern int *out;
extern int k;
extern int j;
extern int i;

void loop(){
for (k = 0; k < 4; k++) {
    int dot_product = 0;
    for (i = 0; i < 1024; i++)
        for (j = 0; j < 1024; j++)
            dot_product += in[i + k][j] * coeff[i][j];
    out[k] = dot_product;
}

}
