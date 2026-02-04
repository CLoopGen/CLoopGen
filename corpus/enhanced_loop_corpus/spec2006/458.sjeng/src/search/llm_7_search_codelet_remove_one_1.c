#include <stdio.h>

#include <inttypes.h>

extern int *marker;
extern int move_ordering[];
extern int num_moves;
extern int i;
extern int best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_best = best;
    for (i = 0; i < num_moves; i++) {
        int candidate = move_ordering[i];
        if (candidate > local_best) {
            local_best = candidate;
            *marker = i;
        }
        best = local_best; // WAW dependency introduced: 'best' is updated every iteration
    }
}
