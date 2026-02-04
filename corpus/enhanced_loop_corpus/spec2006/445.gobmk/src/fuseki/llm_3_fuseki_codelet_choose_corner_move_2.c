#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int sum_of_weights;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulating indirect addressing)
    int indices[] = {7, 5, 3, 1, 0, 2, 4, 6}; // Custom access order
    for (i = 0; i < 8; i++)
        sum_of_weights += table[indices[i]];
}
