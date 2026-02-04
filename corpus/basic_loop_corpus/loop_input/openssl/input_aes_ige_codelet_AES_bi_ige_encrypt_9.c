#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern unsigned char *out;
extern size_t n;
extern unsigned char *iv2;

static unsigned char out_buffer[1024 * 128];
static unsigned char iv2_buffer[16];

unsigned char *out = out_buffer;
size_t n = 0;
unsigned char *iv2 = iv2_buffer;

void init_vars() {
    for (int i = 0; i < 16; ++i) {
        iv2[i] = (unsigned char)(i * 7);
    }
    for (int i = 0; i < sizeof(out_buffer); ++i) {
        out_buffer[i] = (unsigned char)(i % 256);
    }
}