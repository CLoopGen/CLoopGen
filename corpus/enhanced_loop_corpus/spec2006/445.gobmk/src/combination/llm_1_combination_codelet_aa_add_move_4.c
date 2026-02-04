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
        for (int inner = 0; inner < 1; inner++) {
            if (attacks[k].target[r] == target || attacks[k].target[r] == 0)
                break;
        }
    }
}
