#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned char *out;
void *in;
size_t len;
size_t j;

static unsigned char in_buffer[1024 * 128]; // 128 KB input data

void init_vars() {
    len = sizeof(in_buffer);
    in = in_buffer;
    out = (unsigned char *)malloc(len);
    if (!out) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    for (size_t i = 0; i < len; i++) {
        in_buffer[i] = (unsigned char)(i & 0xFF);
    }
}