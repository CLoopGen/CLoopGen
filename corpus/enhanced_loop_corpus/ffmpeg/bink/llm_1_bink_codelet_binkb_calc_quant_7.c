#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t binkb_intra_seed[64];
extern  uint8_t binkb_inter_seed[64];
extern  uint8_t binkb_num[16];
extern  uint8_t binkb_den[16];
extern int32_t binkb_intra_quant[16][64];
extern int32_t binkb_inter_quant[16][64];
extern uint8_t inv_bink_scan[64];
extern  int s[64];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 16; j += 2) {
    for (i = 0; i < 64; i++) {
        int k = inv_bink_scan[i];
        binkb_intra_quant[j][k] = binkb_intra_seed[i] * (int64_t)s[i] * binkb_num[j] / (binkb_den[j] * ((1LL << 30) >> 12));
        binkb_inter_quant[j][k] = binkb_inter_seed[i] * (int64_t)s[i] * binkb_num[j] / (binkb_den[j] * ((1LL << 30) >> 12));
        if (j + 1 < 16) {
            binkb_intra_quant[j+1][k] = binkb_intra_seed[i] * (int64_t)s[i] * binkb_num[j+1] / (binkb_den[j+1] * ((1LL << 30) >> 12));
            binkb_inter_quant[j+1][k] = binkb_inter_seed[i] * (int64_t)s[i] * binkb_num[j+1] / (binkb_den[j+1] * ((1LL << 30) >> 12));
        }
    }
}
}
