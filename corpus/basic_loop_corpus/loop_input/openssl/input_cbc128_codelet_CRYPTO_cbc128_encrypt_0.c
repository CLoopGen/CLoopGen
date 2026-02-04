#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned char *in;
unsigned char *out;
size_t n;
unsigned char *iv;

static unsigned char in_buf[131072];    // 128KB
static unsigned char out_buf[131072];   // 128KB
static unsigned char iv_buf[16];

void init_vars() {
    in = in_buf;
    out = out_buf;
    iv = iv_buf;
    n = 0;

    for (size_t i = 0; i < 16; ++i) {
        iv[i] = (unsigned char)(0x55 ^ i);
    }
    for (size_t i = 0; i < 131072; ++i) {
        in[i] = (unsigned char)i;
    }
    for (size_t i = 0; i < 131072; ++i) {
        out[i] = 0;
    }
}