#include <stdio.h>

#include <inttypes.h>

extern int *spiral_search_x;
extern int *spiral_search_y;
extern int **pos_00;
extern short ref;
extern int list;
extern int ref_x;
extern int ref_y;
extern int pos;
extern int max_pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Increase loop nesting depth by introducing an outer loop that runs once
    for (int outer = 0; outer < 1; outer++) {
        for (pos = 0; pos < max_pos; pos++) {
            if (ref_x == spiral_search_x[pos] && ref_y == spiral_search_y[pos]) {
                pos_00[list][ref] = pos;
                break;
            }
        }
    }
}
