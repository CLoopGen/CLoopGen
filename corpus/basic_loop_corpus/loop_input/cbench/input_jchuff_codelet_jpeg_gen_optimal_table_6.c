#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

long freq[257];
int codesize[257];
int others[257];
int c1;
int c2;
int i;
long v;

void init_vars() {
    // Initialize freq with non-zero values for most entries to ensure loop runs
    for (int idx = 0; idx <= 256; idx++) {
        freq[idx] = (idx + 1) * 100000L; // distinct increasing frequencies
    }
    
    // Ensure at least two elements are small enough to be processed
    freq[0] = 100000L;
    freq[1] = 200000L;
    
    // Initialize codesize and others arrays
    for (int idx = 0; idx <= 256; idx++) {
        codesize[idx] = 0;
        others[idx] = -1; // initially all point to -1 (invalid)
    }
    
    // Reset scalar variables
    c1 = -1;
    c2 = -1;
    i = 0;
    v = 0;
}