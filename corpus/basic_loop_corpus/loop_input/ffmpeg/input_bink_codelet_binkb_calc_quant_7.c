#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t binkb_intra_seed[64];
uint8_t binkb_inter_seed[64];
uint8_t binkb_num[16];
uint8_t binkb_den[16];
int32_t binkb_inter_quant[16][64];
int32_t binkb_intra_quant[16][64];
uint8_t inv_bink_scan[64];
int s[64];
int i;
int j;

void init_vars() {
    for (int idx = 0; idx < 64; idx++) {
        binkb_intra_seed[idx] = (uint8_t)((idx * 7 + 13) % 256);
        binkb_inter_seed[idx] = (uint8_t)((idx * 11 + 17) % 256);
        inv_bink_scan[idx] = (uint8_t)((63 - idx) ^ 7);
        s[idx] = (int)(1000 + idx * 17);
    }
    for (int idx = 0; idx < 16; idx++) {
        binkb_num[idx] = (uint8_t)(1 + (idx * 3) % 31);
        binkb_den[idx] = (uint8_t)(1 + (idx * 5) % 29);
    }
    for (int j_idx = 0; j_idx < 16; j_idx++) {
        for (int i_idx = 0; i_idx < 64; i_idx++) {
            binkb_intra_quant[j_idx][i_idx] = 0;
            binkb_inter_quant[j_idx][i_idx] = 0;
        }
    }
    i = 0;
    j = 0;
}