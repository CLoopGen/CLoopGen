#include <stdio.h>

#include <inttypes.h>

extern int *marker;
extern int move_ordering[];
extern int num_moves;
extern int i;
extern int best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < num_moves && i < 1000; i += 2) {
        if (i + 1 < num_moves) {
            int val1 = move_ordering[i];
            int val2 = move_ordering[i + 1];
            if (val1 > best) {
                *marker = i;
                best = val1;
            }
            if (val2 > best) {
                *marker = i + 1;
                best = val2;
            }
        } else if (move_ordering[i] > best) {
            *marker = i;
            best = move_ordering[i];
        }
    }
}
