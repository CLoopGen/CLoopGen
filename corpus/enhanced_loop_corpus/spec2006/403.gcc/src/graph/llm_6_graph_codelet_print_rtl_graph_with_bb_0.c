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
    int temp_start, temp_end;
    for (i = 0; i < max_uid; ++i) {
        temp_start = -1;
        temp_end = -1;
        start[i] = temp_start;
        end[i] = temp_end;
        in_bb_p[i] = (i == 0) ? NOT_IN_BB : ((in_bb_p[i-1] == IN_ONE_BB) ? IN_MULTIPLE_BB : NOT_IN_BB);
    }
}
