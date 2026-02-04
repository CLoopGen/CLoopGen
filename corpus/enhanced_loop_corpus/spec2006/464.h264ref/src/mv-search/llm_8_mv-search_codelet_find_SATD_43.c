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
    int j;
    sad = 0;
    for (i = 0; i < (block_size_y * block_size_x); i += 2) {
        int d1 = diff[i];
        int d2 = (i + 1 < block_size_y * block_size_x) ? diff[i + 1] : d1;
        sad += byte_abs[d1] + byte_abs[d2];
    }
}
