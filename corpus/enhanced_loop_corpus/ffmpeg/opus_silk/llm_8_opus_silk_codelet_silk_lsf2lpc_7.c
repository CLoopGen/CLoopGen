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
for (k = 0; k < order && k < 16; k++) {
    int index = nlsf[k] >> 8;
    int offset = nlsf[k] & 255;
    int k2 = (order == 10) ? ff_silk_lsf_ordering_nbmb[k] : ff_silk_lsf_ordering_wb[k];
    int32_t cos_val = ff_silk_cosine[index];
    int32_t cos_next = ff_silk_cosine[index + 1];
    lsp[k2] = ((cos_val << 8) + (cos_next - cos_val) * offset + 4) >> 3;
}
}
