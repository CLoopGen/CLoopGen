#include <stdio.h>

#include <inttypes.h>

extern double data[1400][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Block-wise (Tiled) Memory Access Pattern
    int block_size_i = 64;
    int block_size_j = 64;
    for (int ii = 0; ii < 1400; ii += block_size_i)
        for (int jj = 0; jj < 1200; jj += block_size_j)
            for (i = ii; i < ((ii + block_size_i) < 1400 ? ii + block_size_i : 1400); i++)
                for (j = jj; j < ((jj + block_size_j) < 1200 ? jj + block_size_j : 1200); j++)
                    data[i][j] = (double)(i * j) / 1200 + i;
}
