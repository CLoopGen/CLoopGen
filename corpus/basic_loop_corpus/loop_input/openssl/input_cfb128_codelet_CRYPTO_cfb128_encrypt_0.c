#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef size_t size_t_aX __attribute__((aligned(1)));

unsigned char *in;
unsigned char *out;
unsigned char ivec[16];
unsigned int n;

static unsigned char in_buffer[1024 * 128]; // 128KB
static unsigned char out_buffer[1024 * 128]; // 128KB

void init_vars() {
    in = in_buffer;
    out = out_buffer;
    n = 0;

    for (size_t i = 0; i < sizeof(ivec); ++i) {
        ivec[i] = (unsigned char)(i * 37);
    }

    for (size_t i = 0; i < sizeof(in_buffer); ++i) {
        in[i] = (unsigned char)(i % 251);
    }

    for (size_t i = 0; i < sizeof(out_buffer); ++i) {
        out[i] = 0;
    }
}