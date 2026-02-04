#include <stdio.h>

#include <inttypes.h>

extern int move_history_color[500];
extern int move_history_pos[500];
extern int move_history_pointer;
extern int number_collapsed_moves;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int outer = number_collapsed_moves; outer < move_history_pointer; outer++) {
    k = outer;
    for (int inner = 0; inner < 1; inner++) {
        move_history_color[k - number_collapsed_moves] = move_history_color[k];
        move_history_pos[k - number_collapsed_moves] = move_history_pos[k];
    }
}
}
