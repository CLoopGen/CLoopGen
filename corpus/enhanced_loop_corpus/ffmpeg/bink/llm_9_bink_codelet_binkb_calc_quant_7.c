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
for (j = 0; j < 8; j++) {
    int64_t scaled_den[2];
    int64_t scaled_num[2];
    scaled_den[0] = binkb_den[j] * ((1LL << 30) >> 12);
    scaled_den[1] = binkb_den[j + 8] * ((1LL << 30) >> 12);
    scaled_num[0] = binkb_num[j];
    scaled_num[1] = binkb_num[j + 8];

    for (i = 0; i < 64; i += 4) {
        int k0 = inv_bink_scan[i];
        int k1 = inv_bink_scan[i+1];
        int k2 = inv_bink_scan[i+2];
        int k3 = inv_bink_scan[i+3];

        int64_t s0 = s[i], s1 = s[i+1], s2 = s[i+2], s3 = s[i+3];
        int64_t seed_intra0 = binkb_intra_seed[i], seed_intra1 = binkb_intra_seed[i+1];
        int64_t seed_intra2 = binkb_intra_seed[i+2], seed_intra3 = binkb_intra_seed[i+3];
        int64_t seed_inter0 = binkb_inter_seed[i], seed_inter1 = binkb_inter_seed[i+1];
        int64_t seed_inter2 = binkb_inter_seed[i+2], seed_inter3 = binkb_inter_seed[i+3];

        // Unroll and compute for two j indices: j and j+8
        binkb_intra_quant[j][k0]   = (int32_t)((seed_intra0 * s0 * scaled_num[0]) / scaled_den[0]);
        binkb_intra_quant[j][k1]   = (int32_t)((seed_intra1 * s1 * scaled_num[0]) / scaled_den[0]);
        binkb_intra_quant[j][k2]   = (int32_t)((seed_intra2 * s2 * scaled_num[0]) / scaled_den[0]);
        binkb_intra_quant[j][k3]   = (int32_t)((seed_intra3 * s3 * scaled_num[0]) / scaled_den[0]);
        binkb_intra_quant[j+8][k0] = (int32_t)((seed_intra0 * s0 * scaled_num[1]) / scaled_den[1]);
        binkb_intra_quant[j+8][k1] = (int32_t)((seed_intra1 * s1 * scaled_num[1]) / scaled_den[1]);
        binkb_intra_quant[j+8][k2] = (int32_t)((seed_intra2 * s2 * scaled_num[1]) / scaled_den[1]);
        binkb_intra_quant[j+8][k3] = (int32_t)((seed_intra3 * s3 * scaled_num[1]) / scaled_den[1]);

        binkb_inter_quant[j][k0]   = (int32_t)((seed_inter0 * s0 * scaled_num[0]) / scaled_den[0]);
        binkb_inter_quant[j][k1]   = (int32_t)((seed_inter1 * s1 * scaled_num[0]) / scaled_den[0]);
        binkb_inter_quant[j][k2]   = (int32_t)((seed_inter2 * s2 * scaled_num[0]) / scaled_den[0]);
        binkb_inter_quant[j][k3]   = (int32_t)((seed_inter3 * s3 * scaled_num[0]) / scaled_den[0]);
        binkb_inter_quant[j+8][k0] = (int32_t)((seed_inter0 * s0 * scaled_num[1]) / scaled_den[1]);
        binkb_inter_quant[j+8][k1] = (int32_t)((seed_inter1 * s1 * scaled_num[1]) / scaled_den[1]);
        binkb_inter_quant[j+8][k2] = (int32_t)((seed_inter2 * s2 * scaled_num[1]) / scaled_den[1]);
        binkb_inter_quant[j+8][k3] = (int32_t)((seed_inter3 * s3 * scaled_num[1]) / scaled_den[1]);
    }
}
}
