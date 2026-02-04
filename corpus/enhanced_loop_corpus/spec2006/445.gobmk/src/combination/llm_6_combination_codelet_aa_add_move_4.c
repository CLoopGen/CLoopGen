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
    int temp_r = 0;
    for (r = 0; r < 4; r++) {
        temp_r = r;
        if (attacks[k].target[temp_r] == target || attacks[k].target[temp_r] == 0)
            break;
    }
    r = temp_r;
}
