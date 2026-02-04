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
    memset(ivec, 0x5A, 16);
    memset(in, 0xA5, sizeof(in_buffer));
    memset(out, 0, sizeof(out_buffer));
}