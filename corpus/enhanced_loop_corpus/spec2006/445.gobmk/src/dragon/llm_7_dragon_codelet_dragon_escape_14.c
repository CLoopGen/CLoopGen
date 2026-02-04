#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern char goal[400];
extern int ii;
extern int mx[400];
extern int queue[361];
extern int queue_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Introduce loop-carried dependence via mx array used in next iteration's condition
    int prev_valid_index = -1;
    for (ii = (19 + 2); ii < (19 + 1) * (19 + 1); ii++) {
        if ((board[ii] != 3) && goal[ii]) {
            queue[queue_end++] = ii;
            mx[ii] = 1;

            // Create WAW and WAR dependencies: current write affects future read/write through mx
            if (prev_valid_index != -1) {
                mx[ii] += mx[prev_valid_index];  // RAW: use of previous mx value
                mx[prev_valid_index] = 0;        // WAW: overwrite after prior write
            }
            prev_valid_index = ii;
        }
    }
}
