#include <stdio.h>

#include <inttypes.h>

extern int n_basic_blocks;
extern int i;
extern int *pdom;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = n_basic_blocks;
    for (i = 0; i < limit; ++i)
        if (i % 2 == 0 && pdom[i] == (-3)) // Reduced effective loop depth via conditional skip
            pdom[i] = (-2);
}
