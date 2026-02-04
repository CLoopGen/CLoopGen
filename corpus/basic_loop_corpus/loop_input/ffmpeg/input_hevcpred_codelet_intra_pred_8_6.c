#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int size;
ptrdiff_t stride;
uint8_t *src;
uint8_t *left;

void init_vars() {
    size = 64 * 1024 * 1024; // 64 MB data size for ~0.01 sec runtime on modern CPU
    stride = 1;
    src = (uint8_t *)aligned_alloc(32, sizeof(uint8_t) * (size + 1));
    left = (uint8_t *)aligned_alloc(32, sizeof(uint8_t) * size);

    if (!src || !left) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize src with valid data, ensure index (-1 + stride*i) is valid for i in [0, size)
    // So we need src[-1] to src[stride*(size-1)-1] -> requires src[0] at index -1 => allocate extra element at start
    // We access: src[stride*i - 1], for i from 0 to size-1 => indices from -1 to stride*(size-1)-1
    // With stride=1, we need index range [-1, size-2], so we place data starting at index 1 in allocated block
    // Thus base pointer src points to &mem[1], so that src[-1] is mem[0]
    uint8_t *mem = src;
    src = &mem[1];

    for (int idx = 0; idx < size; idx++) {
        mem[idx] = (uint8_t)(idx & 0xFF); // Initialize base memory including the -1 offset location
    }
    for (int idx = 0; idx < size; idx++) {
        left[idx] = 0; // Initialize left array
    }
}