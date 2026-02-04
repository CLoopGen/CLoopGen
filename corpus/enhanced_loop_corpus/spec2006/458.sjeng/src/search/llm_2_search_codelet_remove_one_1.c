#include <stdio.h>

#include <inttypes.h>

extern int *marker;
extern int move_ordering[];
extern int num_moves;
extern int i;
extern int best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled to process two elements per iteration
    int limit = num_moves - (num_moves % 2);
    for (i = 0; i < limit; i += 2) {
        if (move_ordering[i] > best) {
            *marker = i;
            best = move_ordering[i];
        }
        if (move_ordering[i + 1] > best) {
            *marker = i + 1;
            best = move_ordering[i + 1];
        }
    }
    // Handle remaining element if num_moves is odd
    if (limit < num_moves && move_ordering[limit] > best) {
        *marker = limit;
        best = move_ordering[limit];
    }
}
