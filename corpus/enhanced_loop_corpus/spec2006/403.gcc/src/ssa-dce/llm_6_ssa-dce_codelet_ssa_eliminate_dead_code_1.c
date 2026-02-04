#include <stdio.h>

#include <inttypes.h>

extern int n_basic_blocks;
extern int i;
extern int *pdom;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp;
    for (i = 0; i < n_basic_blocks; ++i) {
        temp = pdom[i];
        if (temp == (-3)) {
            pdom[i] = (-2);
        }
    }
}
