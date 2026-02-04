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
    int local_l = l;

    for (i = 0; i < num_moves; i++) {
        int current_nodesspent = nodesspent[i];
        int current_islegal = islegal[i];
        int current_rootloser = rootlosers[i];

        if ((current_nodesspent < leastlooked) && current_islegal && !current_rootloser) {
            leastlooked = current_nodesspent;
            leastlooked_i = i;
            leastlooked_l = local_l;
        }
        if (current_islegal)
            local_l++;
    }

    l = local_l;
}
