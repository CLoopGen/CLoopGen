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
    for (int depth1 = 0; depth1 < 2; depth1++) {
        for (k = depth1 * 3; k < depth1 * 3 + 3 && k < 6; k++) {
            moves[k].pos = 0;
            moves[k].value = -1;
            moves[k].name = ((void *)0);
            moves[k].same_dragon = 2;
        }
    }
}
