#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned char *out;
size_t n;
unsigned char *iv2;

static unsigned char out_buf[131072]; // 128KB
static unsigned char iv2_buf[131072]; // 128KB

void init_vars() {
    out = out_buf;
    iv2 = iv2_buf;
    for (size_t i = 0; i < 131072; ++i) {
        out[i] = (unsigned char)(i & 0xFF);
        iv2[i] = (unsigned char)((i * 3) & 0xFF);
    }
    n = 0;
}