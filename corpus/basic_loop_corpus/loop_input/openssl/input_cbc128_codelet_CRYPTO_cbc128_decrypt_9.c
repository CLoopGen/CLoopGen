#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned char *in;
unsigned char ivec[16];
size_t n;

void init_vars() {
    const size_t input_size = 512 * 1024;
    in = (unsigned char *)malloc(input_size);
    if (!in) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < input_size; ++i) {
        in[i] = (unsigned char)(i & 0xFF);
    }

    n = 0;
    memset(ivec, 0, 16);
}