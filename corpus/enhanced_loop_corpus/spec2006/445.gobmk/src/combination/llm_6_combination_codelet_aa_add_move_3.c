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
    int temp_move = move;
    for (k = 0; k < 19 * 19; k++) {
        if (attacks[k].move == temp_move || attacks[k].move == 0) {
            break;
        }
        temp_move = attacks[k].move; // Introduce WAW dependency: temp_move updated each iteration, creating loop-carried dependence
        move = temp_move; // Write to 'move' creates WAR/WAW with external definition
    }
}
