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
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            k = i * 19 + j;
            if (attacks[k].move == move || attacks[k].move == 0)
                goto exit_loop;
        }
    }
    k = 19 * 19; // In case no break occurs
exit_loop:;
}
