#include <stdio.h>

#include <inttypes.h>

extern int move_history_color[500];
extern int move_history_pos[500];
extern int move_history_pointer;
extern int number_collapsed_moves;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int base = number_collapsed_moves;
    for (k = 0; k < move_history_pointer - base; k++) {
        move_history_color[k] = move_history_color[k + base];
        move_history_pos[k] = move_history_pos[k + base];
    }
}
