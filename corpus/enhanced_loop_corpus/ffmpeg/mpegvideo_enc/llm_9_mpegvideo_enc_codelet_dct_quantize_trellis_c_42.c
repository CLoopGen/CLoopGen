#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern  uint8_t *perm_scantable;
extern int run_tab[65];
extern int level_tab[65];
extern int start_i;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with increased trip count via smaller step
    // Instead of jumping by run_tab[i]+1, we now step by 1, increasing iterations
    // This increases memory accesses but simplifies arithmetic per iteration
    for (; i > start_i; i--) {
        // Only update when cumulative run matches original condition
        int accumulated_run = 0;
        int temp_i = i;
        while (temp_i > i - (run_tab[i] + 1) && temp_i > start_i) {
            block[perm_scantable[temp_i - 1]] = level_tab[i];
            accumulated_run++;
            temp_i--;
        }
        i -= accumulated_run - 1;  // Compensate for inner unrolled-like behavior
    }
}
