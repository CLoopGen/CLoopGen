#include <stdio.h>

#include <inttypes.h>

extern int *marker;
extern int move_ordering[];
extern int num_moves;
extern int i;
extern int best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (num_moves <= 0) {
    // Do nothing, skip loop entirely
} else {
    for (i = 0; i < num_moves; i++) {
        *marker = i;
        best = move_ordering[i];
        break;
    }
    for (i = 1; i < num_moves; i++) {
        if (move_ordering[i] > best) {
            *marker = i;
            best = move_ordering[i];
        }
    }
}
}
