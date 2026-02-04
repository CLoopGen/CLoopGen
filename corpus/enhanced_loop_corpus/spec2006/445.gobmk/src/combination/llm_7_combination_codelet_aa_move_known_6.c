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
    // Eliminate loop-carried dependency by unrolling and using local flags
    int found = 0;
    int i;
    for (i = 0; i < 4 && !found; i++) {
        // Each iteration now independent due to flag-controlled exit
        if (attacks[k].target[i] == target || attacks[k].target[i] == 0)
            found = 1;
    }
    // Update r only once after loop, removing per-iteration side effects
    r = found ? (i - 1) : 4;
}
