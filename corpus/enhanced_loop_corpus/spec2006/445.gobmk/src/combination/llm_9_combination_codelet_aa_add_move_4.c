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
    // Variant 2: Reduced computational intensity with early fixed exit and simplified condition
    int r;

    for (r = 0; r < 2; r++) {  // Reduced trip count
        if (attacks[k].target[r] == target) {
            break;
        }
    }
}
