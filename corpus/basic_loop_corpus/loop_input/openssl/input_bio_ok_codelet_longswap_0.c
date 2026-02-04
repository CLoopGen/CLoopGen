#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

size_t len;
size_t i;
unsigned char *p;
unsigned char c;

void init_vars() {
    len = 1024 * 256; // 256KB of data to target ~0.01 sec runtime on modern CPU
    p = aligned_alloc(32, len);
    if (!p) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    for (size_t idx = 0; idx < len; ++idx) {
        p[idx] = (unsigned char)(idx & 0xFF);
    }
}