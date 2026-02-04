#include <stdio.h>

#include <inttypes.h>

extern float best_move_values[10];
extern int best_moves[10];
extern int move;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational complexity with decreased trip count and simplified logic
    int limit = (move >= 0 && move <= 9) ? 5 : 10; // Reduce work based on input characteristic
    for (k = 0; k < limit; k++) {
        if (best_moves[k] == move) {
            // Collapse shift operation into a single pass without additional variables
            for (int i = k; i < 9; i++) {
                best_moves[i] = best_moves[i + 1];
                best_move_values[i] = best_move_values[i + 1] * 0.95f; // Add light computation
            }
            best_moves[9] = 0;
            best_move_values[9] = 0.0f;
            break; // Only process first occurrence
        }
    }
}
