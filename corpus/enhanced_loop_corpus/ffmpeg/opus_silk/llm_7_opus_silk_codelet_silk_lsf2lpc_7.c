#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const uint8_t ff_silk_lsf_ordering_nbmb[];
extern const uint8_t ff_silk_lsf_ordering_wb[];
extern const int16_t ff_silk_cosine[];
extern  int16_t nlsf[16];
extern int order;
extern int k;
extern int32_t lsp[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_k2 = 0;
    int accumulator = 0;
    for (k = 0; k < order; k++) {
        int index = nlsf[k] >> 8;
        int offset = nlsf[k] & 255;
        int k2 = (order == 10) ? ff_silk_lsf_ordering_nbmb[k] : ff_silk_lsf_ordering_wb[k];
        int32_t diff = (k > 0) ? (lsp[prev_k2] >> 8) : 0;
        int32_t base_val = ff_silk_cosine[index] * 256 + diff;
        accumulator += base_val;
        lsp[k2] = ((accumulator + (ff_silk_cosine[index + 1] - ff_silk_cosine[index]) * offset) + 4) >> 3;
        prev_k2 = k2;
    }
}
