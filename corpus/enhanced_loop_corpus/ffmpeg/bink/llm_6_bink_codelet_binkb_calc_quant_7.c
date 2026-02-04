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
        int32_t num_val = binkb_num[j];
        int32_t den_val = binkb_den[j];
        int64_t scale = den_val * ((1LL << 30) >> 12);
        for (i = 0; i < 64; i++) {
            int k = inv_bink_scan[i];
            int64_t seed_intra = binkb_intra_seed[i];
            int64_t seed_inter = binkb_inter_seed[i];
            int64_t s_val = s[i];
            // Introduce temporary variables to remove repeated memory accesses and create local data dependency
            int64_t product_intra = seed_intra * s_val * num_val;
            int64_t product_inter = seed_inter * s_val * num_val;
            binkb_intra_quant[j][k] = product_intra / scale;
            binkb_inter_quant[j][k] = product_inter / scale;
        }
    }
}
