#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t int_simd16_t;

int16_t FIX_1_414213562_A = 92682;
int16_t FIX_1_847759065 = 121567;
int16_t FIX_2_613125930 = 171619;
int16_t FIX_1_414213562 = 92682;
int16_t FIX_1_082392200 = 70756;

ptrdiff_t output_stride = 8;
int cnt;

int_simd16_t tmp0;
int_simd16_t tmp1;
int_simd16_t tmp2;
int_simd16_t tmp3;
int_simd16_t tmp4;
int_simd16_t tmp5;
int_simd16_t tmp6;
int_simd16_t tmp7;
int_simd16_t tmp10;
int_simd16_t tmp11;
int_simd16_t tmp12;
int_simd16_t tmp13;
int_simd16_t z5;
int_simd16_t z10;
int_simd16_t z11;
int_simd16_t z12;
int_simd16_t z13;

int16_t *outptr;
int16_t *wsptr;

static int16_t out_data[8 * 32768];
static int16_t ws_data[8 * 32768];

void init_vars() {
    for (int i = 0; i < 8 * 32768; i++) {
        out_data[i] = 0;
        ws_data[i] = rand() % 1000 - 500;
    }
    outptr = out_data;
    wsptr = ws_data;
    cnt = 32768;
}