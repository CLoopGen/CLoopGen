#include <stdio.h>

#include <inttypes.h>

extern float best_move_values[10];
extern int best_moves[10];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_vals[10];
    int temp_moves[10];

    for (k = 0; k < 10; k++) {
        temp_moves[k] = 0;
        temp_vals[k] = 0.;
    }

    for (k = 0; k < 10; k++) {
        best_moves[k] = temp_moves[k];
        best_move_values[k] = temp_vals[k];
    }
}
