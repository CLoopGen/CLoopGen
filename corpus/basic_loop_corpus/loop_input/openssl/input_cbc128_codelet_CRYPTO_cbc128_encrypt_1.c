#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef size_t size_t_aX __attribute__((aligned(1)));

unsigned char *in;
unsigned char *out;
size_t n;
unsigned char *iv;

void init_vars() {
    size_t data_size = 256 * 1024; // 256KB, sufficient for ~0.01 sec runtime

    in = (unsigned char *)aligned_alloc(1, data_size);
    out = (unsigned char *)aligned_alloc(1, data_size);
    iv = (unsigned char *)aligned_alloc(1, 16);

    if (!in || !out || !iv) {
        exit(1);
    }

    memset(in, 0x55, data_size);
    memset(out, 0x00, data_size);
    memset(iv, 0xAA, 16);

    n = 0;
}