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
for (j = 0; j < 16; j++) {
    int skip_loop = (binkb_num[j] == 0 || binkb_den[j] == 0);
    for (i = 0; i < 64 && !skip_loop; i++) {
        int k = inv_bink_scan[i];
        int valid_input = (binkb_intra_seed[i] != 0 || binkb_inter_seed[i] != 0);
        if (valid_input) {
            int64_t scale = (int64_t)s[i] * binkb_num[j] / (binkb_den[j] * ((1LL << 30) >> 12));
            binkb_intra_quant[j][k] = binkb_intra_seed[i] * scale;
            binkb_inter_quant[j][k] = binkb_inter_seed[i] * scale;
        } else {
            binkb_intra_quant[j][k] = 0;
            binkb_inter_quant[j][k] = 0;
        }
    }
    if (skip_loop) {
        continue;
    }
}
}
