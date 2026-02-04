#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int left;
extern int top;
extern int width;
extern int height;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Consecutive linear traversal using a single loop with row-major simulation
int total_elements = width * height;
for (int idx = 0; idx < total_elements; ++idx) {
    // Map linear index to 2D coordinates: j = row, i = column
    int j = top + idx / width;
    int i = left + idx % width;
    // Simulate consecutive access pattern in memory
    volatile int dummy = i + j; // Placeholder operation representing memory access
}
}
