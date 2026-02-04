#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned char *raxKey;
uint64_t bucketKey;

void init_vars() {
    raxKey = aligned_alloc(32, 1024 * 1024); // Allocate 1MB
    if (!raxKey) {
        exit(1);
    }
    for (int i = 0; i < 1024 * 1024; ++i) {
        raxKey[i] = (unsigned char)(i & 0xFF);
    }
    bucketKey = 0x123456789ABCDEF0ULL;
}