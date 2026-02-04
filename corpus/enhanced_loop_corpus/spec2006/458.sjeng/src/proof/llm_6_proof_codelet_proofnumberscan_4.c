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
    int temp_leastlooked = leastlooked;
    int temp_leastlooked_i = leastlooked_i;
    int temp_leastlooked_l = leastlooked_l;
    int temp_l = l;

    for (i = 0; i < num_moves; i++) {
        if ((nodesspent[i] < temp_leastlooked) && islegal[i] && !rootlosers[i]) {
            temp_leastlooked = nodesspent[i];
            temp_leastlooked_i = i;
            temp_leastlooked_l = temp_l;
        }
        if (islegal[i])
            temp_l++;
    }

    leastlooked = temp_leastlooked;
    leastlooked_i = temp_leastlooked_i;
    leastlooked_l = temp_leastlooked_l;
    l = temp_l;
}
