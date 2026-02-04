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
    // Variant 1: Consecutive memory access with loop unrolling by factor of 2
    int i;
    for (i = 0; i < max_uid - 1; i += 2) {
        start[i] = end[i] = -1;
        in_bb_p[i] = NOT_IN_BB;
        start[i + 1] = end[i + 1] = -1;
        in_bb_p[i + 1] = NOT_IN_BB;
    }
    // Handle remaining element if max_uid is odd
    if (i < max_uid) {
        start[i] = end[i] = -1;
        in_bb_p[i] = NOT_IN_BB;
    }
}
