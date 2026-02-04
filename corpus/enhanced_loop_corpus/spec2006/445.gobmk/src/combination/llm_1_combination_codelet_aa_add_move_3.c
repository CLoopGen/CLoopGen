#include <stdio.h>

#include <inttypes.h>

struct aa_move {
    int move;
    int target[4];
};


extern struct aa_move attacks[361];
extern int move;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int found = 0;
    for (int outer = 0; outer < 1 && !found; outer++) {
        for (k = 0; k < 19 * 19; k++) {
            if (attacks[k].move == move || attacks[k].move == 0) {
                found = 1;
                break;
            }
        }
    }
}
