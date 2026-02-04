#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct FilterParams {
    uint8_t order;
    uint8_t shift;
    int32_t state[8];
    int coeff_bits;
    int coeff_shift;
} FilterParams;

typedef struct ChannelParams {
    FilterParams filter_params[2];
    int32_t coeff[2][8];
    int16_t huff_offset;
    int32_t sign_huff_offset;
    uint8_t codebook;
    uint8_t huff_lsbs;
} ChannelParams;

ChannelParams *dst_cp;
ChannelParams *src_cp;
int filter;
FilterParams *dst;
unsigned int order;

void init_vars() {
    src_cp = (ChannelParams*)calloc(1, sizeof(ChannelParams));
    dst_cp = (ChannelParams*)calloc(1, sizeof(ChannelParams));
    
    filter = 0;
    dst = &src_cp->filter_params[0];
    dst->order = 8;
    dst->shift = 0;
    dst->coeff_bits = 16;
    dst->coeff_shift = 12;
    for (int i = 0; i < 8; i++) {
        dst->state[i] = 0;
    }

    for (int f = 0; f < 2; f++) {
        for (int i = 0; i < 8; i++) {
            src_cp->coeff[f][i] = (int32_t)(i * 100 + f);
            dst_cp->coeff[f][i] = 0;
        }
        src_cp->filter_params[f].order = 8;
        src_cp->filter_params[f].shift = f;
        src_cp->filter_params[f].coeff_bits = 16;
        src_cp->filter_params[f].coeff_shift = 12;
        for (int j = 0; j < 8; j++) {
            src_cp->filter_params[f].state[j] = j * 50 + f;
        }
    }

    src_cp->huff_offset = 42;
    src_cp->sign_huff_offset = 123456;
    src_cp->codebook = 1;
    src_cp->huff_lsbs = 7;

    dst_cp->huff_offset = 0;
    dst_cp->sign_huff_offset = 0;
    dst_cp->codebook = 0;
    dst_cp->huff_lsbs = 0;
}