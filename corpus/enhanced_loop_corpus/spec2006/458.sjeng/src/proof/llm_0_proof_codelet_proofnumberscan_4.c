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
for (i = 0; i < num_moves; i++) {
    for (int j = 0; j < 1; j++) { // Increased depth: added a nested loop with fixed iteration
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
