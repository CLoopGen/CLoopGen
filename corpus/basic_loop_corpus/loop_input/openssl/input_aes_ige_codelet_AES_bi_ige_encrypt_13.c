#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

unsigned char *out;
size_t n;
unsigned char *iv;

static unsigned char out_buffer[1024 * 128]; // 128KB buffer
static unsigned char iv_buffer[16];          // iv is accessed up to index 15

void init_vars() {
    out = out_buffer;
    iv = iv_buffer;
    n = 0;

    // Initialize iv with non-zero values for meaningful XOR operations
    for (size_t i = 0; i < 16; ++i) {
        iv[i] = (unsigned char)(0x55 ^ i);
    }

    // Initialize out buffer with predictable pattern
    for (size_t i = 0; i < sizeof(out_buffer); ++i) {
        out_buffer[i] = (unsigned char)(0xAA & i);
    }
}