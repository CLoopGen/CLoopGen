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
        if (islegal[i]) {
            if ((nodesspent[i] < leastlooked) && !rootlosers[i]) {
                leastlooked = nodesspent[i];
                leastlooked_i = i;
                leastlooked_l = l;
            }
            l++;
        } else {
            if ((nodesspent[i] < leastlooked) && !rootlosers[i]) {
                leastlooked = nodesspent[i];
                leastlooked_i = i;
                leastlooked_l = l;
            }
        }
    }
}
