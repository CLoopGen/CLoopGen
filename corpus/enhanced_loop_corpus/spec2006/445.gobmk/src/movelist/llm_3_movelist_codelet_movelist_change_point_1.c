#include <stdio.h>

#include <inttypes.h>

extern int move;
extern int max_points;
extern int points[];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via arithmetic)
    // Simulate indirect access by accessing points in reverse order
    for (k = 0; k < max_points; k++) {
        int idx = max_points - 1 - k;  // Reverse traversal
        if (points[idx] == move) {
            k = idx;  // Store the actual index where match occurred
            break;
        }
    }
}
