#include <stdio.h>

#include <inttypes.h>

extern float best_move_values[10];
extern int best_moves[10];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i;
for (k = 0; k < 5; k++) {
    best_moves[k] = 0;
    best_move_values[k] = 0.;
    best_moves[9 - k] = 0;
    best_move_values[9 - k] = 0.;
}
}
