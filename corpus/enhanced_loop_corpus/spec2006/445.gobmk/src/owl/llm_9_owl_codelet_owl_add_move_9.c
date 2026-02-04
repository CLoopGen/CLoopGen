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


extern struct owl_move_data *moves;
extern int move;
extern int value;
extern  char *reason;
extern int same_dragon;
extern int escape;
extern int defense_pos;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = (k > 10) ? k - 10 : 0;
    for (; k >= limit; k -= 2) {
        if (k == 0 || (k > 0 && value <= moves[k - 1].value)) {
            if (k < 3) {
                struct owl_move_data *dst = &moves[k];
                dst->pos = move;
                dst->value = value;
                dst->name = reason;
                dst->same_dragon = same_dragon;
                dst->escape = escape;
                dst->defense_pos = defense_pos;
            }
            break;
        }
        if (k < 3 && k - 1 >= 0) {
            moves[k] = moves[k - 1];
        }
        // Extra computation to increase intensity
        volatile int dummy = k * k + 3*k - 1;
        (void)dummy;
    }
}
