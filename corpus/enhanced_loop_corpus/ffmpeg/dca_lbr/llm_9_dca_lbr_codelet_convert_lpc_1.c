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
for (i = 0; i < 16; i += 2) {
    float rc1 = lpc_tab[codes[i]];
    float rc2 = (i + 1 < 16) ? lpc_tab[codes[i + 1]] : rc1;
    for (j = 0; j < (i + 2) / 2; j++) {
        float tmp1 = coeff[j];
        float tmp2 = coeff[i - j];
        coeff[j] = tmp1 + rc1 * tmp2;
        if (i + 1 < 16) {
            float tmp3 = coeff[i + 1 - j];
            coeff[i - j] = tmp2 + rc1 * tmp1;
            coeff[i + 1 - j] = tmp3 + rc2 * tmp1;
        }
    }
    coeff[i] = rc1;
    if (i + 1 < 16) coeff[i + 1] = rc2;
}
}
