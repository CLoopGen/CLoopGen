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
    k = 0;
    for (y = 0; y < block_size_y; y++) {
        for (x = 0; x < block_size_x; x++) {
            if (y % block_size == 0 && x % block_size == 0) {
                for (j = y; j < y + block_size && j < block_size_y; j++) {
                    for (i = x; i < x + block_size && i < block_size_x; i++) {
                        diff[k] = curr_diff[j][i];
                        k++;
                    }
                }
            }
        }
    }
}
