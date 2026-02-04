#include <stdio.h>

#include <inttypes.h>

extern int n_basic_blocks;
extern int *degree;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < n_basic_blocks * 2; i++) {
        j = i / 2;
        if (j < n_basic_blocks)
            degree[j] = (degree[j] + i) * (i % 2 + 1);
    }
}
