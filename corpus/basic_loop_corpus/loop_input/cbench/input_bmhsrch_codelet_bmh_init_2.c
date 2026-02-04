#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef unsigned char uchar;

int patlen;
int skip2;
uchar *pat;
int i;
int lastpatchar;

void init_vars() {
    // Set pattern length to approximately 64MB to ensure loop runtime around 0.01s
    // on modern CPUs (adjustable based on profiling, but this is a reasonable estimate)
    patlen = 64 * 1024 * 1024;
    
    // Allocate memory for pattern
    pat = (uchar*)malloc(patlen);
    if (!pat) {
        patlen = 0;
        skip2 = 1;
        lastpatchar = 0;
        return;
    }
    
    // Initialize pattern with pseudo-random data based on time and address
    // to avoid compiler optimizations assuming constant values
    uint64_t seed = (uint64_t)&pat + (uint64_t)time(NULL);
    for (int j = 0; j < patlen; ++j) {
        seed = seed * 6364136223846793005ULL + 1;
        pat[j] = (uchar)(seed >> 32);
    }
    
    // Set lastpatchar to a value likely to appear in the pattern
    lastpatchar = 42;
    
    // Ensure pat[0..patlen-2] will be accessed safely in loop (i < patlen - 1)
    // So we must have patlen >= 1 to avoid underflow, but malloc ensures that
    
    // Initialize skip2 to a default value (will be updated in loop)
    skip2 = 1;
}