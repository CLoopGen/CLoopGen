#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t cos_tbl[64];
extern  int16_t cos_derivative_tbl[64];
extern int16_t *lsf;
extern int16_t *lsp;
extern int order;
extern int16_t diff;
extern int16_t freq;
extern int32_t tmp;
extern int i;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < order; i++) {
    freq = (lsf[i] * 20861) >> 15;
    k = freq >> 8;
    diff = freq & 255;
    if (k < 64) {
        tmp = cos_derivative_tbl[k] * diff;
        lsp[i] = cos_tbl[k] + (tmp >> 12);
    } else {
        tmp = cos_derivative_tbl[63] * diff;
        lsp[i] = cos_tbl[63] + (tmp >> 12);
    }
}
}
