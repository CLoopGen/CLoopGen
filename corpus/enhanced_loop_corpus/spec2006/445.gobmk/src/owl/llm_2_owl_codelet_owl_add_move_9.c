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



void loop() {
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing moves[k] and moves[k-1], we simulate a strided access by introducing a stride variable.
    // Here, we use a fixed stride of 1 but express indices using arithmetic to emphasize pattern change.
    int stride = 1;
    for (; k >= 0; k -= stride) {
        int prev_idx = k - stride;
        if (k == 0 || value <= moves[prev_idx].value) {
            if (k < 3) {
                moves[k].pos = move;
                moves[k].value = value;
                moves[k].name = reason;
                moves[k].same_dragon = same_dragon;
                moves[k].escape = escape;
                moves[k].defense_pos = defense_pos;
            }
            break;
        }
        if (k < 3)
            moves[k] = moves[prev_idx];
    }
}
