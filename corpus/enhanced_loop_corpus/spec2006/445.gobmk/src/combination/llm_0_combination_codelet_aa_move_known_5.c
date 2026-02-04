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
int k1, k2;
for (k1 = 0; k1 < 19; k1++) {
    for (k2 = 0; k2 < 19; k2++) {
        k = k1 * 19 + k2;
        if (attacks[k].move == move || attacks[k].move == 0)
            goto exit_loop;
    }
}
exit_loop:;
}
