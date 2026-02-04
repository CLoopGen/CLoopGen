#include <stdio.h>

#include <inttypes.h>

extern int *byte_abs;
extern int i;
extern int sad;
extern int block_size_x;
extern int block_size_y;
extern int diff[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_sad = 0;
    for (int j = 0; j < block_size_y; j++)
        for (int k = 0; k < block_size_x; k++)
            temp_sad += byte_abs[diff[j * block_size_x + k]];
    sad += temp_sad;
}
