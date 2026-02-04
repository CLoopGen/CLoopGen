#include <stdio.h>

#include <inttypes.h>

extern int curr_diff[16][16];
extern int i;
extern int j;
extern int k;
extern int x;
extern int y;
extern int block_size_x;
extern int block_size_y;
extern int block_size;
extern int diff[256];

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (y = 0; y < block_size_y; y += block_size)
    for (x = 0; x < block_size_x; x += block_size)
        for (j = y; j < y + block_size; j++)
            for (i = x; i < x + block_size; i++ , k++)
                diff[k] = curr_diff[j][i];

}
