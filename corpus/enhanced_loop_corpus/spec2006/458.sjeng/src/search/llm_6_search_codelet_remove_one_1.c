#include <stdio.h>

#include <inttypes.h>

extern int *marker;
extern int move_ordering[];
extern int num_moves;
extern int i;
extern int best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_best = best;
    int temp_marker = *marker;
    for (i = 0; i < num_moves; i++) {
        if (move_ordering[i] > temp_best) {
            temp_best = move_ordering[i];
            temp_marker = i;
        }
    }
    best = temp_best;
    *marker = temp_marker;
}
