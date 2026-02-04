#include <stdio.h>

#include <inttypes.h>

extern int n_basic_blocks;
extern int *degree;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < n_basic_blocks; j++)
        for (i = 0; i < 1; i++)
            degree[j] = 0;
}
