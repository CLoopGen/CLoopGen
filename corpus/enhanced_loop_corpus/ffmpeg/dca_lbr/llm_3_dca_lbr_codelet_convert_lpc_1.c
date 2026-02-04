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
for (i = 0; i < 8; i++) {
    float rc = lpc_tab[codes[i]];
    float temp_coeff[8];
    int bound = (i + 1) / 2;
    for (j = 0; j < 8; j++) {
        temp_coeff[j] = coeff[j];
    }
    for (j = 0; j < bound; j++) {
        float tmp1 = temp_coeff[j];
        float tmp2 = temp_coeff[i - j - 1];
        coeff[j] = tmp1 + rc * tmp2;
        coeff[i - j - 1] = tmp2 + rc * tmp1;
    }
    coeff[i] = rc;
}
}
