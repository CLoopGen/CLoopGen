#include <stdio.h>

#include <inttypes.h>

extern int r;
extern int distances[362];
extern int num_moves;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via arithmetic pattern)
    // Simulating indirect access by accessing elements in non-linear order: r * r % num_moves, bounded safely
    for (r = 0; r < num_moves; r++) {
        int idx = (r * r) % (num_moves > 0 ? num_moves : 1); // Avoid mod by zero
        if (distances[idx] > distances[0] + 1500)
            break;
    }
}
