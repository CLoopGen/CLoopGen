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
    // Variant 2: Reduced trip count with simplified condition and added arithmetic complexity
    int r;
    for (r = 0; r < 2; r++) {
        int scaled_target = target * 2;
        if ((attacks[k].target[r * 2] * 2 == scaled_target || attacks[k].target[r * 2] == 0) &&
            (attacks[k].target[r * 2 + 1] * 2 == scaled_target || attacks[k].target[r * 2 + 1] == 0)) {
            break;
        }
    }
}
