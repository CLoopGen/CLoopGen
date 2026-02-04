#include <stdio.h>

#include <inttypes.h>

extern float best_move_values[10];
extern int best_moves[10];
extern int move;
extern float val;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_vals[10];
    int temp_moves[10];
    int write_index = 0;
    for (k = 0; k < 10; k++) {
        if (val > best_move_values[k]) {
            temp_vals[write_index] = val;
            temp_moves[write_index] = move;
            write_index++;
            for (int j = k; j < 9; j++) {
                temp_vals[write_index] = best_move_values[j];
                temp_moves[write_index] = best_moves[j];
                write_index++;
            }
            break;
        } else {
            temp_vals[write_index] = best_move_values[k];
            temp_moves[write_index] = best_moves[k];
            write_index++;
        }
    }
    for (k = 0; k < 10; k++) {
        best_move_values[k] = temp_vals[k];
        best_moves[k] = temp_moves[k];
    }
}
