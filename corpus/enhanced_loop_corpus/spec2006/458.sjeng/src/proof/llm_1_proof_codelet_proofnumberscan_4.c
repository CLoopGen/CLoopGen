#include <stdio.h>

#include <inttypes.h>

extern int rootlosers[300];
extern int islegal[512];
extern int nodesspent[512];
extern int i;
extern int l;
extern int num_moves;
extern int leastlooked;
extern int leastlooked_l;
extern int leastlooked_i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (num_moves > 0) {
    for (i = 0; i < num_moves; i += 2) { // Decreased effective depth by unrolling: simulate two iterations per step
        // First iteration of the pair
        if ((nodesspent[i] < leastlooked) && islegal[i] && !rootlosers[i]) {
            leastlooked = nodesspent[i];
            leastlooked_i = i;
            leastlooked_l = l;
        }
        if (islegal[i])
            l++;

        // Second iteration, if within bounds
        if (i + 1 < num_moves) {
            if ((nodesspent[i+1] < leastlooked) && islegal[i+1] && !rootlosers[i+1]) {
                leastlooked = nodesspent[i+1];
                leastlooked_i = i+1;
                leastlooked_l = l;
            }
            if (islegal[i+1])
                l++;
        }
    }
} else {
    // Handle empty case explicitly to preserve original control flow
    for (i = 0; i < num_moves; i++) {
        if ((nodesspent[i] < leastlooked) && islegal[i] && !rootlosers[i]) {
            leastlooked = nodesspent[i];
            leastlooked_i = i;
            leastlooked_l = l;
        }
        if (islegal[i])
            l++;
    }
}
}
