#include <stdio.h>

#include <inttypes.h>

struct owl_move_data {
    int pos;
    int value;
    const char *name;
    int same_dragon;
    int escape;
    int defense_pos;
};


extern struct owl_move_data moves[6];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with loop unrolling factor of 2
    int upper = 2 * 2 + 2;
    for (k = 0; k < upper; k += 2) {
        // First element in pair
        if (k < upper) {
            moves[k].pos = 0;
            moves[k].value = -1;
            moves[k].name = ((void *)0);
            moves[k].same_dragon = 2;
        }
        // Second element in pair
        if (k + 1 < upper) {
            moves[k + 1].pos = 0;
            moves[k + 1].value = -1;
            moves[k + 1].name = ((void *)0);
            moves[k + 1].same_dragon = 2;
        }
    }
}
