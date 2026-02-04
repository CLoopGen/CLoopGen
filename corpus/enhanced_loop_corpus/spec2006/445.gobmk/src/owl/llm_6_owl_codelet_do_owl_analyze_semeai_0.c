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
    // Variant 1: Introduce loop-carried dependency (WAW and RAW) by making each iteration depend on the previous one
    // This creates a sequential dependency where current iteration writes affect future reads
    int prev_value = -1;
    for (k = 0; k < 2 * 2 + 2; k++) {
        moves[k].pos = 0;
        moves[k].value = prev_value - 1;           // RAW: uses prev_value from prior iteration
        moves[k].name = ((void *)0);
        moves[k].same_dragon = 2;
        prev_value = moves[k].value;               // WAW: ensures write to prev_value is carried to next
    }
}
