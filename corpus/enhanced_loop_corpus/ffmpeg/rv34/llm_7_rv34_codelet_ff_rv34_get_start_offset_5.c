#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t rv34_mb_max_sizes[6];
extern int mb_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int found = 0;
    for (i = 0; i < 5 && !found; i++) {
        int cmp_result = (rv34_mb_max_sizes[i] >= mb_size - 1);  // Introduce local computation (RAW: use after read)
        if (cmp_result) {
            found = 1;  // Introduce loop-carried dependency via 'found' flag (WAW on found)
            i++;        // Modify loop index inside body (WAR: write after read of i in condition)
        }
    }
    if (found)
        i--;  // Adjust i to point to the matching index (compensate extra increment)
}
