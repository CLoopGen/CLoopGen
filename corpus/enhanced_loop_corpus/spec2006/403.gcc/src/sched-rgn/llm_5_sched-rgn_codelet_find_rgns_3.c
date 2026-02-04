#include <stdio.h>

#include <inttypes.h>

extern int n_basic_blocks;
extern int *max_hdr;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n_basic_blocks; i++) {
        max_hdr[i] = -1;
        if (i == n_basic_blocks / 2) {
            i++; // Skip the next element arbitrarily to demonstrate control variation
        }
    }
}
