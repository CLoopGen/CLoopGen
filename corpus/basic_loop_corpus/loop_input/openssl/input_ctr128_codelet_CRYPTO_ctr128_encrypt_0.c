#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef size_t size_t_aX __attribute__((aligned(1)));

unsigned char *in;
unsigned char *out;
unsigned char ecount_buf[16];
unsigned int n;

static unsigned char in_buf[1024 * 128];     // 128KB input buffer
static unsigned char out_buf[1024 * 128];    // 128KB output buffer

void init_vars() {
    in = in_buf;
    out = out_buf;
    n = 0;

    for (size_t i = 0; i < sizeof(in_buf); ++i) {
        in_buf[i] = (unsigned char)(i & 0xFF);
    }
    for (size_t i = 0; i < sizeof(out_buf); ++i) {
        out_buf[i] = 0;
    }
    for (size_t i = 0; i < 16; ++i) {
        ecount_buf[i] = (unsigned char)((i * 7) & 0xFF);
    }
}