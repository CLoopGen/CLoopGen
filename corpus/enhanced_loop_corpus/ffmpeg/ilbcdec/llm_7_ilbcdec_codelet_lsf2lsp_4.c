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
    int32_t temp_result[64];
    for (i = 0; i < order; i++) {
        freq = (lsf[i] * 20861) >> 15;
        k = (freq >> 8) > 63 ? 63 : (freq >> 8);
        diff = freq & 255;
        tmp = cos_derivative_tbl[k] * diff;
        temp_result[i] = cos_tbl[k] + (tmp >> 12);
    }
    for (i = 0; i < order; i++) {
        lsp[i] = temp_result[i];
    }
}
