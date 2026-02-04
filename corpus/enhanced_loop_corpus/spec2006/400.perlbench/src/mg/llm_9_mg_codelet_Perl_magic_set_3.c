#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern int PL_origargc;
extern char **PL_origargv;
extern I32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced effective trip count with stride-based skipping and added lightweight condition
    I32 step = 3;
    for (i = 1; i < PL_origargc; i += step) {
        // Only process every third argument, reducing total iterations
        if ((i % 2) == 1) {
            PL_origargv[i] = 0;
        }
        // Additional minimal arithmetic to maintain computational balance
        step = (step + (i % 2)) & 3; // vary step slightly without breaking loop bounds
    }
}
