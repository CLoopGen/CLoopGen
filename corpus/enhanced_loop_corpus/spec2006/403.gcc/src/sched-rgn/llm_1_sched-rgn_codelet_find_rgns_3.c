#include <stdio.h>

#include <inttypes.h>

extern int n_basic_blocks;
extern int *max_hdr;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (n_basic_blocks > 0) {
        i = 0;
        for (; i < n_basic_blocks; i++)
            max_hdr[i] = -1;
    }
}
