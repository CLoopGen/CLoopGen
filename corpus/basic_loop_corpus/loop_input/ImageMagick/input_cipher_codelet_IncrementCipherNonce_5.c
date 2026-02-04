#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t length = 1 << 20; // 1MB of data

unsigned char *nonce;

ssize_t i;

void init_vars() {
    nonce = aligned_alloc(32, length);
    if (!nonce) {
        exit(1);
    }
    for (size_t idx = 0; idx < length; idx++) {
        nonce[idx] = 0;
    }
}