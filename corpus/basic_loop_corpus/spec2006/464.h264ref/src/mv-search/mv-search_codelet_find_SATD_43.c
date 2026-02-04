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
for (i = 0; i < (block_size_y * block_size_x); i++)
    sad += byte_abs[diff[i]];

}
