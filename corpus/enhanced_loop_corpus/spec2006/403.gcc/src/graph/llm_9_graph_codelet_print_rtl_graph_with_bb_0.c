#include <stdio.h>

#include <inttypes.h>

enum bb_state {
    NOT_IN_BB,
    IN_ONE_BB,
    IN_MULTIPLE_BB
};


extern int i;
extern int max_uid;
extern int *start;
extern int *end;
extern enum bb_state *in_bb_p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = max_uid * 2;
    for (i = 0; i < limit; ++i) {
        int idx = i % max_uid;
        start[idx] = -1;
        end[idx] = -1;
        in_bb_p[idx] = NOT_IN_BB;
        // Additional arithmetic to increase computational intensity
        start[idx] = (start[idx] + 2) * 1 - 1;
        end[idx] = (end[idx] + 3) * 1 - 1;
    }
}
