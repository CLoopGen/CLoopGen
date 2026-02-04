#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef size_t size_t_aX __attribute__((aligned(1)));

size_t n;
size_t_aX *out_t;
size_t_aX *iv_t;

void init_vars() {
    const size_t array_size = 1024 * 128 / sizeof(size_t); // ~128KB of data
    out_t = aligned_alloc(_Alignof(size_t), array_size * sizeof(size_t));
    iv_t = aligned_alloc(_Alignof(size_t), array_size * sizeof(size_t));

    for (size_t i = 0; i < array_size; i++) {
        out_t[i] = i ^ 0x12345678;
        iv_t[i] = i ^ 0x87654321;
    }
}