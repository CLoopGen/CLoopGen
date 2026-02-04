#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

char outbuf[16];
char *bp2;
int i;

static char bp2_storage[16];

void init_vars() {
    // Initialize outbuf with known non-zero pattern to make XOR observable
    for (int j = 0; j < 16; ++j) {
        outbuf[j] = (char)(0x55 + j);
    }
    
    // Initialize bp2_storage
    for (int j = 0; j < 16; ++j) {
        bp2_storage[j] = (char)(0xAA - j);
    }
    
    // Set bp2 pointer to point to bp2_storage
    bp2 = bp2_storage;
    
    // Initialize loop counter
    i = 0;
}