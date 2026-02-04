#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t int_simd16_t;

int16_t FIX_0_382683433 = 25172;
int16_t FIX_0_541196100 = 35468;
int16_t FIX_0_707106781 = 46341;
int16_t FIX_1_306562965 = 85738;

uint8_t *pixels;
ptrdiff_t line_size;
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
int_simd16_t z1;
int_simd16_t z2;
int_simd16_t z3;
int_simd16_t z4;
int_simd16_t z5;
int_simd16_t z11;
int_simd16_t z13;

int16_t *dataptr;

uint8_t *pixels_buffer;
int16_t *dataptr_buffer;

void init_vars() {
    line_size = 16;
    size_t total_pixels_size = 134217728; // ~128MB to target ~0.01s runtime with reasonable stride
    pixels_buffer = (uint8_t*)aligned_alloc(32, total_pixels_size);
    dataptr_buffer = (int16_t*)aligned_alloc(32, total_pixels_size / 2);

    if (!pixels_buffer || !dataptr_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < total_pixels_size; i++) {
        pixels_buffer[i] = (uint8_t)(i % 256);
    }

    for (size_t i = 0; i < total_pixels_size / 2; i++) {
        dataptr_buffer[i] = (int16_t)(i % 65536);
    }

    pixels = pixels_buffer;
    dataptr = dataptr_buffer;

    cnt = (total_pixels_size / line_size) / 8;
    if (cnt > 16777216) cnt = 16777216;
}