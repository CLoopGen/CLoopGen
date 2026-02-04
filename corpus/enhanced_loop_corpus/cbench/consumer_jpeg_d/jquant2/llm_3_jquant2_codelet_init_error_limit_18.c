#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index mapping array
    // Simulate indirect access using a precomputed index permutation (conceptually)
    // Since we can't define new global arrays, simulate with arithmetic-based indirection
    int indices[2] = {in, -in};  // Simulated indirect indices
    for (; in <= 255; in++) {
        table[indices[0]] = out;
        table[indices[1]] = -out;
        // Update indices for next iteration as if following an irregular pattern
        indices[0] = in + 1;
        indices[1] = -(in + 1);
    }
}
