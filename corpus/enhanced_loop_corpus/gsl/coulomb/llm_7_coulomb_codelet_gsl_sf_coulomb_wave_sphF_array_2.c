#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int kmax;
extern double x;
extern double *fc_array;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double prev = 0.0;
    if (kmax >= 0) {
        prev = fc_array[0]; // Initialize with first element
        fc_array[0] = prev / x;
    }
    for (k = 1; k <= kmax; k++) {
        double current = fc_array[k];
        // Introduce loop-carried dependency: current computation depends on previous result
        fc_array[k] = current / x + prev; // WAR hazard introduced via 'prev' reuse
        prev = current; // Update prev for next iteration — creates artificial loop-carried flow dependency
    }
}
