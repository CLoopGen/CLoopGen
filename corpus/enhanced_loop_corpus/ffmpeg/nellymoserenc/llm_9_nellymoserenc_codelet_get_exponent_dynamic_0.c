#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int band;
extern int best_idx;
extern float best_val;
extern float (*opt)[35768];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Higher trip count with lighter per-iteration computation
    // Introduce stride-based sampling to increase iteration count but reduce cache pressure
    int step = 1;
    int limit = (1 << 16); // Increased trip count beyond original (~65536 vs ~34768)
    for (i = 0; i < limit; i += step) {
        // Use modulo to wrap around array bounds safely
        int actual_idx = i % ((1 << 15) + 3000);
        float current_val = opt[band][actual_idx];

        // Simplified comparison with no extra local variables
        best_val = (best_val > current_val) ? current_val : best_val;
        best_idx = (best_val > current_val) ? actual_idx : best_idx;
    }
}
