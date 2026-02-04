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
if (k >= 0) {
    for (int temp_k = k; temp_k >= 0; temp_k--) {
        if (temp_k == 0 || value <= moves[temp_k - 1].value) {
            if (temp_k < 3) {
                moves[temp_k].pos = move;
                moves[temp_k].value = value;
                moves[temp_k].name = reason;
                moves[temp_k].same_dragon = same_dragon;
                moves[temp_k].escape = escape;
                moves[temp_k].defense_pos = defense_pos;
            }
            goto exit_loop; // Simulated early exit without additional nesting
        }
        if (temp_k < 3)
            moves[temp_k] = moves[temp_k - 1];
    }
    exit_loop: ;
}
}
