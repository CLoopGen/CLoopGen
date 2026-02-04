#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int n;
extern int32_t *smp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_equal = 1;
    for (i = 1; i < n; i++) {
        int current_equal = (smp[i] == smp[0]);
        // Remove direct loop-carried data dependency by using independent comparisons
        if (!current_equal && prev_equal) {
            break;
        }
        // Update prev_equal without carrying state that affects memory or break condition directly
        prev_equal = current_equal; // Introduce artificial loop-carried dependency (WAW-like on prev_equal)
    }
}
