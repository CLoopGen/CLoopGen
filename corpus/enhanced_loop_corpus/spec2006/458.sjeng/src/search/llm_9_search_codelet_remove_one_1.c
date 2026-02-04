#include <stdio.h>

#include <inttypes.h>

extern int *marker;
extern int move_ordering[];
extern int num_moves;
extern int i;
extern int best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int threshold = best - 10;
    for (i = 0; i < num_moves; i++) {
        int current = move_ordering[i];
        int diff = current - best;
        if (diff > 0) {
            *marker = i;
            best = current;
        }
        if (current <= threshold && i + 1 < num_moves) {
            i++; // Skip next element if below aggressive pruning threshold
        }
    }
}
