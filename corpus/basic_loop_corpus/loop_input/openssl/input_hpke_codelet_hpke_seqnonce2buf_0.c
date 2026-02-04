#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned char *buf;
size_t blen;
size_t i;
uint64_t seq_copy;

void init_vars() {
    blen = 512 * 1024; // 512 KB buffer
    buf = (unsigned char *)malloc(blen);
    if (!buf) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    seq_copy = 0xABCDEF1234567890ULL;
}

__attribute__((destructor))
void cleanup() {
    free(buf);
}