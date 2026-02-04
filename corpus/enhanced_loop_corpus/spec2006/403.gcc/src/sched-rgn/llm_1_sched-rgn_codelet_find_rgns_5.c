#include <stdio.h>

#include <inttypes.h>

extern int n_basic_blocks;
extern int *degree;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n_basic_blocks; i++) {
        degree[i] = 0;
        for (int j = 0; j < 1; j++);
    }
}
