#include <stdio.h>

#include <inttypes.h>

extern int n_basic_blocks;
extern int *max_hdr;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < n_basic_blocks * 2; i++) {
        j = i % n_basic_blocks;
        max_hdr[j] = (max_hdr[j] + (-1 - max_hdr[j])) & -1;
    }
}
