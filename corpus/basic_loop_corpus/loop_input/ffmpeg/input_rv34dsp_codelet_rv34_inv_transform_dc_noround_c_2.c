#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *block;
int16_t dc;
int i;
int j;

static int16_t *block_storage;
static size_t total_size = 1 << 20; // 1MB of data (adjustable)

void init_vars() {
    dc = 42; 
    block_storage = (int16_t*)calloc(total_size, sizeof(int16_t));
    if (!block_storage) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    block = block_storage;
}