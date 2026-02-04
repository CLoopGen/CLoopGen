#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern unsigned char *out;
extern size_t n;
extern unsigned char *iv;

static unsigned char out_buf[1024 * 128];
static unsigned char iv_buf[16];

unsigned char *out = out_buf;
size_t n;
unsigned char *iv = iv_buf;

void init_vars() {
    for (size_t i = 0; i < sizeof(iv_buf); ++i) {
        iv[i] = (unsigned char)(i * i + 3);
    }
    for (size_t i = 0; i < sizeof(out_buf); ++i) {
        out_buf[i] = (unsigned char)(i % 251);
    }
}