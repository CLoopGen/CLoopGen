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
    
    for (i = 0; i < num_moves; i += 2) {
        if (i + 1 < num_moves) {
            int val1 = nodesspent[i];
            int val2 = nodesspent[i+1];
            int legal1 = islegal[i];
            int legal2 = islegal[i+1];
            int loser1 = rootlosers[i];
            int loser2 = rootlosers[i+1];

            if (legal1 && !loser1 && (val1 < temp_leastlooked)) {
                temp_leastlooked = val1;
                temp_leastlooked_i = i;
                temp_leastlooked_l = temp_l;
            }
            if (legal2 && !loser2 && (val2 < temp_leastlooked)) {
                temp_leastlooked = val2;
                temp_leastlooked_i = i+1;
                temp_leastlooked_l = temp_l + (legal1 ? 1 : 0);
            }
            temp_l += legal1 + legal2;
        } else {
            if ((nodesspent[i] < temp_leastlooked) && islegal[i] && !rootlosers[i]) {
                temp_leastlooked = nodesspent[i];
                temp_leastlooked_i = i;
                temp_leastlooked_l = temp_l;
            }
            if (islegal[i])
                temp_l++;
        }
    }

    leastlooked = temp_leastlooked;
    leastlooked_i = temp_leastlooked_i;
    leastlooked_l = temp_leastlooked_l;
    l = temp_l;
}
