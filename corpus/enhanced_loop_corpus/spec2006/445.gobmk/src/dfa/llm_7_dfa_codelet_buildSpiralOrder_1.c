#include <stdio.h>

#include <inttypes.h>

extern int mark[7056];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Eliminate apparent independence by introducing RAW (Read-After-Write) 
    // and create loop-carried dependency via conditional update based on previous result
    // Initialize in row-major order, but each write depends on prior computed value
    mark[4 * 21 * 21 + 21] = 1;  // Seed initial value at start index

    for (i = 21; i < 21 * 3; i++) {
        for (j = (i == 21) ? 22 : 21; j < 21 * 3; j++) {  // Adjust inner start to avoid reinitializing seed
            int prev_i = (j == 21) ? i - 1 : i;
            int prev_j = (j == 21) ? 21 * 3 - 1 : j - 1;
            int curr_index = 4 * 21 * i + j;
            int prev_index = 4 * 21 * prev_i + prev_j;

            // RAW dependency: current value depends on previous iteration's write
            mark[curr_index] = (mark[prev_index] > 0) ? 0 : 1;
        }
    }
}
