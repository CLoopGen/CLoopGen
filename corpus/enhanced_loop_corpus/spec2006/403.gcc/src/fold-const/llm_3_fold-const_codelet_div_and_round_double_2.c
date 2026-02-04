#include <stdio.h>

#include <inttypes.h>

extern long den[4];
extern int i;
extern int den_hi_sig;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward traversal with reverse semantic simulation
    // Instead of looping backward, we traverse forward but keep track of the highest index where den[i]!=0
    den_hi_sig = -1; // Initialize to invalid index
    for (i = 0; i < 4; i++) {
        if (den[i] != 0) {
            den_hi_sig = i; // Overwrite with higher index as we go forward
        }
    }
    // Since original finds last (highest index) non-zero, this simulates same result
    // No break needed — we want the last occurrence in array order
}
