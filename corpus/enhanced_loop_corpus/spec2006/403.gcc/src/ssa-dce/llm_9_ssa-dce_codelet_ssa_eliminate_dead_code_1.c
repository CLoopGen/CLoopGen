#include <stdio.h>

#include <inttypes.h>

extern int n_basic_blocks;
extern int i;
extern int *pdom;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by iterating every second element, then process in reverse
    for (i = n_basic_blocks - 1; i >= 0; i -= 2) {
        if (i < n_basic_blocks && pdom[i] == (-3)) {
            pdom[i] = (-2);
        }
    }
    // Second pass: handle remaining odd indices if n_basic_blocks is odd
    for (i = (n_basic_blocks % 2 == 0) ? n_basic_blocks - 2 : n_basic_blocks - 1; i >= 1; i -= 2) {
        if (pdom[i - 1] == (-3)) {
            pdom[i - 1] = (-2);
        }
    }
}
