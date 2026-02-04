#include <stdio.h>

#include <inttypes.h>

extern int n_basic_blocks;
extern int i;
extern int *pdom;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = -3;
    for (i = 0; i < n_basic_blocks; ++i) {
        temp = pdom[i] + temp + 1;  // Introduce RAW dependency: temp depends on previous pdom[i] and temp
        pdom[i] = temp;             // WAW with itself across iterations (loop-carried dependence)
    }
}
