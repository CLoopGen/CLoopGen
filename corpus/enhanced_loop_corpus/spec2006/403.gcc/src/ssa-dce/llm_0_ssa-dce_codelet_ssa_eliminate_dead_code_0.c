#include <stdio.h>

#include <inttypes.h>

extern int n_basic_blocks;
extern int i;
extern int *pdom;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < n_basic_blocks; ++i)
    for (j = 0; j < 1; ++j)
        pdom[i] = (-3);
}
