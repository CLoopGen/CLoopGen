#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int size = 64;
int x;
int y;
int i;
int j;
uint32_t *dst;
int dst_linesize;
uint32_t *pal;

void init_vars() {
    dst_linesize = size * 4;
    int total_elements_dst = (16 * dst_linesize + 16) * size + size;
    dst = (uint32_t*)calloc(total_elements_dst, sizeof(uint32_t));
    pal = (uint32_t*)calloc(256, sizeof(uint32_t));
}

// Note: The actual memory access pattern in the loop implies:
//   dst[(y * dst_linesize + x) * size + j * dst_linesize + i]
// We treat `dst` as a large flattened array with sufficient padding.
// With size=64, we have 16x16 blocks of size x size, each block row-strided by dst_linesize.
// Total approximate data written: 16*16*size*size = 16*16*64*64 = 1048576 elements = ~4MB (assuming uint32_t).
// This should run around tens of milliseconds on modern CPUs.