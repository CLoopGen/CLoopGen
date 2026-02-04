#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *left;
extern int *right;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_i = 0;
    for (i = 1; i < ni; ++i) {
        int jj;
        // Introduce loop-carried RAW dependency on previous i value via j
        j += (i - prev_i); // Add distance from last i: creates RAW and loop-carried flow dep
        for (jj = left[i]; jj <= right[i]; ++jj) {
            if (jj > 0) {
                j++; // Maintain increment, now data-dependent on both loops
            }
        }
        prev_i = i; // Update for next iteration's dependency
    }
}
