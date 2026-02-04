#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

uint8_t *clear;
size_t clear_size;
int same;
int i;

void init_vars() {
    clear_size = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec runtime
    clear = aligned_alloc(32, clear_size);
    if (!clear) {
        exit(1);
    }
    memset(clear, 0x5A, clear_size); // Initialize with non-zero uniform value
    same = 1;
    i = 0;
}