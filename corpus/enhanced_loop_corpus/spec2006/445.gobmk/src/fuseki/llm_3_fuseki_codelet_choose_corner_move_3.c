#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int i;
extern int q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulating non-sequential access)
    int indices[] = {7, 5, 3, 1, 0, 2, 4, 6}; // Reverse and alternating pattern
    for (i = 0; i < 8; i++) {
        q -= table[indices[i]];
        if (q < 0)
            break;
    }
}
