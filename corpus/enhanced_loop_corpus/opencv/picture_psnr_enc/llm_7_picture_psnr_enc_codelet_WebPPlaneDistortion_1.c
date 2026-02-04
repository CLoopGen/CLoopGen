#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int height;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_x = 0;
    for (y = 0; y < height; ++y) {
        for (x = 0; x < width; ++x) {
            // Introduce RAW dependency: current computation depends on previous iteration's x
            if (x > 0) {
                prev_x = x + prev_x;  // Loop-carried RAW dependency across x iterations
            } else {
                prev_x = 0;
            }
        }
        // Eliminate loop-carried dependency across y by resetting logic
        prev_x = 0;
    }
}
