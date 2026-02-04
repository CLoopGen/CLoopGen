#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int bitinv32[32];
extern int *out;
extern int *tab;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_index = 0;
    for (i = 0; i < 32; i++) {
        int curr_index = bitinv32[i] + prev_index; // Introduce loop-carried dependence (RAW)
        out[i] = tab[curr_index & 31];            // Ensure index within bounds
        prev_index = curr_index;                  // Create WAW and WAR via `prev_index`
    }
}
