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
    int stride = 1;
    int limit = (num_moves > 256) ? 256 : num_moves;
    int local_l = l;
    int local_leastlooked = leastlooked;
    int local_leastlooked_i = leastlooked_i;
    int local_leastlooked_l = leastlooked_l;

    for (i = 0; i < limit; i++) {
        int index = i * stride;

        if ((nodesspent[index] < local_leastlooked) && islegal[index] && !rootlosers[index]) {
            local_leastlooked = nodesspent[index];
            local_leastlooked_i = index;
            local_leastlooked_l = local_l;
        }
        if (islegal[index])
            local_l++;

        if (i % 32 == 31) {
            local_leastlooked += 1;
        }
    }

    leastlooked = local_leastlooked;
    leastlooked_i = local_leastlooked_i;
    leastlooked_l = local_leastlooked_l;
    l = local_l;
}
