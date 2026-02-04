#include <stdio.h>

#include <inttypes.h>

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

extern const int jpeg_natural_order[];
extern JCOEFPTR block;
extern long ac_counts[];
extern int temp;
extern int nbits;
extern int k;
extern int r;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int local_ac_counts[256] = {0}; // Introduce private storage to eliminate WAR/WAW across iterations
    int local_r = r; // Break loop-carried dependency on 'r' by using local accumulator

    for (k = 1; k < 64; k++) {
        temp = block[jpeg_natural_order[k]];
        if (temp == 0) {
            local_r++;
        } else {
            // Process runs of 16 using for loop instead of while
            for (; local_r > 15; local_r -= 16) {
                local_ac_counts[240]++;
            }
            // Absolute value without branching (data flow variation)
            temp = (temp < 0) ? -temp : temp;
            nbits = 0;
            for (int mask = 1; mask <= temp && mask != 0; mask <<= 1) {
                nbits++;
            }
            local_ac_counts[(local_r << 4) + nbits]++;
            local_r = 0;
        }
    }

    // Merge local counts back to global ac_counts
    for (int i = 0; i < 256; i++) {
        ac_counts[i] += local_ac_counts[i];
    }
    r = local_r; // Update final value of r after loop
}
