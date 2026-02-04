#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *seq;
int len;
int bpos;
int spos;
char twobit;
int i;

void init_vars() {
    len = 67108864; // ~64MB, should take around 0.01s on modern CPU
    seq = (char*)malloc(len);
    if (!seq) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    // Initialize seq with packed data: each byte holds 4 two-bit values
    // Values are in range 0-3, representing C,T,A,G respectively
    for (int j = 0; j < len; j++) {
        // Random-like but deterministic pattern
        seq[j] = (j ^ (j << 2) ^ (j << 4) ^ (j << 6)) & 0xFF;
    }
    
    // Ensure bpos starts at correct position
    bpos = (len - 1) / 4;
    spos = bpos * 4;
    twobit = 0;
    i = 0;
}