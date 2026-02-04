#include <stdio.h>

#include <inttypes.h>

extern float best_move_values[10];
extern int best_moves[10];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < 10; k++) {
    for (int j = 0; j < 1; j++) {
        best_moves[k] = 0;
        best_move_values[k] = 0.;
    }
}
}
