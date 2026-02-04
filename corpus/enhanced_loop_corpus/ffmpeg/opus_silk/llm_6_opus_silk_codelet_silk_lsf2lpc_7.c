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
    int32_t temp_lsp[16] = {0};
    for (k = 0; k < order; k++) {
        int index = nlsf[k] >> 8;
        int offset = nlsf[k] & 255;
        int k2 = (order == 10) ? ff_silk_lsf_ordering_nbmb[k] : ff_silk_lsf_ordering_wb[k];
        int32_t base = ff_silk_cosine[index] * 256;
        int32_t delta = (ff_silk_cosine[index + 1] - ff_silk_cosine[index]) * offset;
        temp_lsp[k2] = (base + delta + 4) >> 3;
    }
    for (k = 0; k < 16; k++) {
        lsp[k] = temp_lsp[k];
    }
}
