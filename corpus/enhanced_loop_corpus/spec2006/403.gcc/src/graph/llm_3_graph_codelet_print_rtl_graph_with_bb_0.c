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
    // Variant 2: Strided memory access with stride of 4 (access every 4th element first, then next lane)
    int stride = 4;
    int phase, i;
    for (phase = 0; phase < stride; ++phase) {
        for (i = phase; i < max_uid; i += stride) {
            start[i] = end[i] = -1;
            in_bb_p[i] = NOT_IN_BB;
        }
    }
}
