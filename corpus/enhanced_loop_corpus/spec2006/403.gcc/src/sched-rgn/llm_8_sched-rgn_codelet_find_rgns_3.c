#include <stdio.h>

#include <inttypes.h>

extern int n_basic_blocks;
extern int *max_hdr;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n_basic_blocks; i += 2) {
        max_hdr[i] = -1;
        if (i + 1 < n_basic_blocks)
            max_hdr[i + 1] = -1;
    }
}
