#include <stdio.h>

#include <inttypes.h>

extern int *marker;
extern int move_ordering[];
extern int num_moves;
extern int i;
extern int best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (num_moves > 0) {
        for (i = 0; i < num_moves; i += 2) {
            int j = i + 1;
            if (move_ordering[i] > best) {
                *marker = i;
                best = move_ordering[i];
            }
            if (j < num_moves && move_ordering[j] > best) {
                *marker = j;
                best = move_ordering[j];
            }
        }
    }
}
