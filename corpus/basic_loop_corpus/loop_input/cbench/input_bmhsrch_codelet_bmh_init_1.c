#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef unsigned char uchar;

int patlen;
int skip[256];
uchar *pat;
int i;

void init_vars() {
    // Set pattern length to ensure noticeable execution time
    // A larger patlen increases loop iterations and memory usage
    patlen = 1000000; // 1M iterations ~ suitable for ~0.01 sec on modern CPU

    // Allocate pattern buffer
    pat = (uchar*)malloc(patlen * sizeof(uchar));
    
    // Initialize skip table to safe default (e.g., patlen)
    for (int j = 0; j < 256; ++j) {
        skip[j] = patlen;
    }

    // Seed random for diverse byte values in pattern
    srand((unsigned int)(time(NULL) ^ (uintptr_t)&pat));

    // Fill pattern with random bytes to ensure all skip entries might be updated
    for (int k = 0; k < patlen; ++k) {
        pat[k] = (uchar)(rand() % 256);
    }
}