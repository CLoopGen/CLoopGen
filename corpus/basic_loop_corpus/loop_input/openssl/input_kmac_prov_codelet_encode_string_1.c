#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

#define DATA_SIZE (512 * 1024) // 512 KB for ~0.01 sec runtime

unsigned char *out;
size_t i;
size_t bits;
size_t len;

static unsigned char out_buffer[DATA_SIZE];

void init_vars() {
    len = DATA_SIZE - 1; // Ensure out[len] is valid and out[i] access stays in bounds
    out = out_buffer;
    bits = 0xABCDEF123456789FULL; // Arbitrary large value to shift and store
    i = len;
    memset(out, 0, DATA_SIZE);
}