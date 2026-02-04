#include <stdio.h>

#include <inttypes.h>

extern int n_basic_blocks;
extern int i;
extern int *pdom;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (n_basic_blocks > 0) {
    for (i = 0; i < n_basic_blocks; ++i)
        pdom[i] = (-3);
}
}
