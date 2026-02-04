#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
enum MLPChMode {
    MLP_CHMODE_LEFT_RIGHT,
    MLP_CHMODE_LEFT_SIDE,
    MLP_CHMODE_RIGHT_SIDE,
    MLP_CHMODE_MID_SIDE
};


extern uint64_t score[4];
extern int i;
extern enum MLPChMode best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 3; i++) {
        best = (score[i] < score[best]) ? i : best;
    }
}
