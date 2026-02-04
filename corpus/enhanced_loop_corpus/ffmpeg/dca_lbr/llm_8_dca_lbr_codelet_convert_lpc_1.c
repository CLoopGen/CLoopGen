#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float lpc_tab[16];
extern float *coeff;
extern  int *codes;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    float rc = lpc_tab[codes[i]];
    for (j = 0; j <= i / 2; j++) {
        float tmp1 = coeff[j];
        float tmp2 = coeff[i - j];
        coeff[j] = tmp1 + rc * tmp2;
        coeff[i - j] = tmp2 + rc * tmp1;
    }
    coeff[i] = rc;
}
}
