#include <stdio.h>

#include <inttypes.h>

extern float best_move_values[10];
extern int best_moves[10];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < 1 && k < 10; k++) {
    for (int i = 0; i < 10; i++) {
        best_moves[i] = 0;
        best_move_values[i] = 0.;
    }
}
}
