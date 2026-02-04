#include <stdio.h>

#include <inttypes.h>

extern int n_basic_blocks;
extern int *degree;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n_basic_blocks; i += 2) {
        degree[i] = 0;
        if (i + 1 < n_basic_blocks)
            degree[i + 1] = 0;
    }
}
