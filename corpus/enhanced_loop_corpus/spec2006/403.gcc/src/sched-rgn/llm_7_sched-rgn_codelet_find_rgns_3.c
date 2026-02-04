#include <stdio.h>

#include <inttypes.h>

extern int n_basic_blocks;
extern int *max_hdr;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < n_basic_blocks; i++)
        max_hdr[i] = max_hdr[i-1];
    if (n_basic_blocks > 0)
        max_hdr[0] = -1;
}
