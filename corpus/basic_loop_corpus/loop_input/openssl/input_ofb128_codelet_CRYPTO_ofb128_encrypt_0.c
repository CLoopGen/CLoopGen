#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef size_t size_t_aX __attribute__((aligned(1)));

unsigned char *in;
unsigned char *out;
unsigned char ivec[16];
unsigned int n;

static unsigned char in_buf[131072];   // 128KB
static unsigned char out_buf[131072];  // 128KB

void init_vars() {
    in = in_buf;
    out = out_buf;
    n = 0;
    for (size_t i = 0; i < 16; ++i) {
        ivec[i] = (unsigned char)(i * 7);
    }
    for (size_t i = 0; i < 131072; ++i) {
        in_buf[i] = (unsigned char)(i ^ 0xAA);
        out_buf[i] = 0x00;
    }
}