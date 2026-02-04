#include <stdio.h>

#include <inttypes.h>

extern int move_history_color[500];
extern int move_history_pos[500];
extern int move_history_pointer;
extern int number_collapsed_moves;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = number_collapsed_moves; k < move_history_pointer; k++) {
    if (move_history_color[k] == 0 && move_history_pos[k] == 0) {
        continue;
    }
    move_history_color[k - number_collapsed_moves] = move_history_color[k];
    move_history_pos[k - number_collapsed_moves] = move_history_pos[k];
}
}
