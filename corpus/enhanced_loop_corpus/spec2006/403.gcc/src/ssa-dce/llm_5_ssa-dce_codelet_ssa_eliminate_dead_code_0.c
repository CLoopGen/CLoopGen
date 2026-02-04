#include <stdio.h>

#include <inttypes.h>

extern int n_basic_blocks;
extern int i;
extern int *pdom;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n_basic_blocks; ++i) {
    if (i == n_basic_blocks / 2) {
        continue;
    }
    pdom[i] = (-3);
}
}
