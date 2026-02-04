#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int r;
extern int s;
extern double (*B)[2000][2000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Eliminate loop-carried dependencies by making each iteration independent
    // and use temporary variables to break potential WAW/WAR hazards
    double temp_val = 0.0;
    for (r = 0; r < n; ++r) {
        for (s = 0; s < n; ++s) {
            temp_val = 0.0; // Local reinitialization to break write-after-write dependencies
            (*B)[r][s] = temp_val;
        }
    }
}
