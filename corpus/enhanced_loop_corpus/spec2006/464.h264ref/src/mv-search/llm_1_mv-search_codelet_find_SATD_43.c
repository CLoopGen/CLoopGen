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
    sad = 0;
    for (int j = 0; j < block_size_y * block_size_x; j += 4) {
        int sum = 0;
        for (int k = 0; k < 4 && (j + k) < (block_size_y * block_size_x); k++) {
            sum += byte_abs[diff[j + k]];
        }
        sad += sum;
    }
}
