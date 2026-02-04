#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned char *digest;
unsigned char hash[20];
int j;

void init_vars() {
    // Allocate 16 MB for digest to ensure loop takes significant time
    // Since the loop only accesses first 20 bytes, we can have large buffer
    digest = (unsigned char *)malloc(16 << 20);
    if (!digest) {
        exit(1);
    }

    // Initialize digest and hash with non-zero values for meaningful XOR
    for (int i = 0; i < 20; i++) {
        digest[i] = (unsigned char)(i * i + 1);
        hash[i] = (unsigned char)(i + 10);
    }
}