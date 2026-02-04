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
int j;
for (j = 0; j < max_uid; ++j) {
    for (i = j; i < max_uid; ++i) {
        start[i] = end[i] = -1;
        in_bb_p[i] = NOT_IN_BB;
    }
}
}
