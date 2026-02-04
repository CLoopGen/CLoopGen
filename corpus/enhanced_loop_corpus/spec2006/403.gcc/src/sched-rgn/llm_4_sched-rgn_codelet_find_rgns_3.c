#include <stdio.h>

#include <inttypes.h>

extern int n_basic_blocks;
extern int *max_hdr;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n_basic_blocks; i++) {
        if (i % 2 == 0) {
            max_hdr[i] = -1;
        } else {
            continue;
        }
    }
}
