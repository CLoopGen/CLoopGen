#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern char escape_value[400];
extern int ii;
extern char escape_values[400][2];
extern int cache_number;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulated via arithmetic progression)
    int indices[200]; // Approximate size needed
    int count = 0;
    int start = (19 + 2);
    int end = (19 + 1) * (19 + 1);
    // Precompute a non-sequential access pattern (e.g., reverse order with step)
    for (int temp = end - 1; temp >= start; temp -= 2) {
        indices[count++] = temp;
    }
    // Access arrays indirectly through the precomputed index list
    for (ii = 0; ii < count; ii++) {
        int idx = indices[ii];
        if (idx < end && (board[idx] != 3))
            escape_value[idx] = escape_values[idx][cache_number];
    }
}
