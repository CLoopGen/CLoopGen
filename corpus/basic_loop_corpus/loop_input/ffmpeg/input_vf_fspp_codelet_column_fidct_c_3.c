#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t int_simd16_t;

int16_t FIX_0_382683433 = 25172;
int16_t FIX_0_541196100 = 35470;
int16_t FIX_0_707106781 = 46341;
int16_t FIX_1_306562965 = 85728;
int16_t FIX_1_414213562_A = 92682;
int16_t FIX_1_847759065 = 121096;
int16_t FIX_2_613125930 = 171455;
int16_t FIX_1_414213562 = 92682;
int16_t FIX_1_082392200 = 70940;

int cnt;
int ctr;

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
int_simd16_t z1;
int_simd16_t z2;
int_simd16_t z3;
int_simd16_t z4;
int_simd16_t z5;
int_simd16_t z10;
int_simd16_t z11;
int_simd16_t z12;
int_simd16_t z13;
int_simd16_t d0;
int_simd16_t d1;
int_simd16_t d2;
int_simd16_t d3;
int_simd16_t d4;
int_simd16_t d5;
int_simd16_t d6;
int_simd16_t d7;

int16_t *thr_adr;
int16_t *dataptr;
int16_t *wsptr;
int16_t *threshold;

#define DATA_SIZE (64 * 1024 * 1024 / sizeof(int16_t))
static int16_t data_buffer[DATA_SIZE];
static int16_t ws_buffer[DATA_SIZE];
static int16_t thr_buffer[8];

void init_vars() {
    cnt = 16384;
    
    thr_adr = thr_buffer;
    dataptr = data_buffer;
    wsptr = ws_buffer;
    
    for (int i = 0; i < 8; i++) {
        thr_buffer[i] = 100 + i * 10;
    }
    
    for (int i = 0; i < DATA_SIZE; i++) {
        data_buffer[i] = (i * 17) % 251 - 125;
        ws_buffer[i] = (i * 97) % 251 - 125;
    }
}