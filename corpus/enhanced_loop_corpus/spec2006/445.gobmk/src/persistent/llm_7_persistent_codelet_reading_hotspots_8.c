#include <stdio.h>

#include <inttypes.h>

extern int board_size;
extern float values[400];
extern int m;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int idx;
    float local_sum = 0.0;
    for (m = 0; m < board_size; m++) {
        for (n = 0; n < board_size; n++) {
            idx = (19 + 2) + m * (19 + 1) + n;
            values[idx] = 0.0;
            local_sum += values[idx]; // Introduce artificial dependency on previous write (WAW-like, though trivial)
        }
    }
    // Use local_sum to prevent dead code elimination
    if (local_sum != 0.0) {
        values[(19 + 2)] = local_sum;
    }
}
