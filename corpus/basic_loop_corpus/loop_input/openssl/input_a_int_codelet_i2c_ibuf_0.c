#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

unsigned char *b;
size_t blen;
unsigned int pad;
size_t i;

void init_vars() {
    blen = 512 * 1024; // 512 KB of data
    b = (unsigned char *)malloc(blen);
    if (!b) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize buffer with non-zero pattern to ensure realistic execution
    for (size_t j = 0; j < blen; j++) {
        b[j] = (unsigned char)(j ^ (j >> 8) ^ 0xAA);
    }

    // Ensure valid initial state for loop variables
    pad = 0;
    i = 1;
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}