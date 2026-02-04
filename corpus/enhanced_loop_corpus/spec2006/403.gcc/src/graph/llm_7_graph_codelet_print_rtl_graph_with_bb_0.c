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
    for (i = 0; i < max_uid; ++i) {
        in_bb_p[i] = NOT_IN_BB;
    }
    for (i = 0; i < max_uid; ++i) {
        start[i] = -1;
    }
    for (i = 0; i < max_uid; ++i) {
        end[i] = -1;
    }
}
