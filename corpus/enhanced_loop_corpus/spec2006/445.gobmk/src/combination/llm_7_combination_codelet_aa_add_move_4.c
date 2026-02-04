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
    int local_k = k;
    int found = 0;
    for (r = 0; r < 4 && !found; r++) {
        if (attacks[local_k].target[r] == target || attacks[local_k].target[r] == 0)
            found = 1;
    }
    if (found)
        r--;
}
