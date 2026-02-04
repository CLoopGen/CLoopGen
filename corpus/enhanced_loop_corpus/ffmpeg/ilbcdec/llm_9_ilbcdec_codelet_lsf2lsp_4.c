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
    int32_t scaled_lsf = lsf[i] * 20861LL;
    freq = (int16_t)(scaled_lsf >> 15);
    k = (freq >> 8);
    if (k > 63) k = 63;
    diff = (int16_t)(freq & 255);
    int32_t derivative_val = cos_derivative_tbl[k];
    tmp = derivative_val * diff;
    int32_t cosine_val = cos_tbl[k];
    lsp[i] = (int16_t)(cosine_val + (tmp >> 12));
}
}
