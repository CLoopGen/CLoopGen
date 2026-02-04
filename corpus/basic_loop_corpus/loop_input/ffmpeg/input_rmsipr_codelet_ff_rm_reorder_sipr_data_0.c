#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned char sipr_swaps[38][2] = {
    {0, 1}, {2, 3}, {4, 5}, {6, 7}, {8, 9}, {10, 11}, {12, 13}, {14, 15},
    {16, 17}, {18, 19}, {20, 21}, {22, 23}, {24, 25}, {26, 27}, {28, 29},
    {30, 31}, {32, 33}, {34, 35}, {36, 37}, {1, 3}, {5, 7}, {9, 11}, {13, 15},
    {17, 19}, {21, 23}, {25, 27}, {29, 31}, {33, 35}, {37, 36}, {2, 4}, {6, 8},
    {10, 12}, {14, 16}, {18, 20}, {22, 24}, {26, 28}, {30, 32}, {34, 36}
};

uint8_t *buf;
int n;
int bs;

void init_vars() {
    bs = 65536; // Block size: 64KB
    size_t buf_size = 2 * bs * 38; // Ensure enough space for all accesses
    buf = (uint8_t*)aligned_alloc(16, buf_size);
    if (!buf) exit(1);
    for (size_t i = 0; i < buf_size; i++) {
        buf[i] = (uint8_t)(i & 0xFF);
    }
}