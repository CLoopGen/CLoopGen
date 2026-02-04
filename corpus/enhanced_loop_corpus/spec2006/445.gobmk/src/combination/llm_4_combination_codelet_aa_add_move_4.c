#include <stdio.h>

#include <inttypes.h>

struct aa_move {
    int move;
    int target[4];
};


extern struct aa_move attacks[361];
extern int target;
extern int k;
extern int r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (r = 0; r < 4; r++) {
        if (attacks[k].target[r] == target) {
            break;
        }
        if (attacks[k].target[r] == 0) {
            break;
        }
    }
}
