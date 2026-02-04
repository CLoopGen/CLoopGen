#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned char *indata;
unsigned char *outdata;
unsigned int *d;
unsigned int x;
unsigned int y;
unsigned int tx;
unsigned int ty;
size_t i;

static unsigned char indata_buf[1024 * 1024];
static unsigned char outdata_buf[1024 * 1024];
static unsigned int d_buf[256];

void init_vars() {
    indata = indata_buf;
    outdata = outdata_buf;
    d = d_buf;
    x = 0;
    y = 0;
    tx = 0;
    ty = 0;
    i = 131072 / 8;  // Process 131072 bytes in chunks of 8 -> ~16384 iterations

    for (size_t j = 0; j < 256; ++j) {
        d[j] = j;
    }

    for (size_t j = 0; j < 1024 * 1024; ++j) {
        indata_buf[j] = (unsigned char)(j & 0xFF);
    }

    memset(outdata_buf, 0, sizeof(outdata_buf));
}