#include <stdio.h>

#include <inttypes.h>

extern int n_basic_blocks;
extern int i;
extern int *pdom;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_index = -1;
    for (i = 0; i < n_basic_blocks; ++i) {
        if (prev_index != -1 && pdom[prev_index] == (-2)) {
            pdom[i] = (-2);
        }
        if (pdom[i] == (-3)) {
            pdom[i] = (-2);
        }
        prev_index = i;
    }
}
