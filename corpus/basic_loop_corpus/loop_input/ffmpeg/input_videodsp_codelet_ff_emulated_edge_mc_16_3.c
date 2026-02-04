#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int block_w;
int x;
int end_x;
uint16_t *bufp;

void init_vars() {
    block_w = 131072; // 256KB of data (131072 elements * 2 bytes = 256KB)
    end_x = 65536;
    bufp = (uint16_t*)calloc(block_w, sizeof(uint16_t));
    if (!bufp) exit(1);
}