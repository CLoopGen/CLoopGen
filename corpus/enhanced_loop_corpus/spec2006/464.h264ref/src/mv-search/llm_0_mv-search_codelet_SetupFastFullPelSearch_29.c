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
    for (int i = 0; i < max_pos; i++) {
        if (ref_x == spiral_search_x[i] && ref_y == spiral_search_y[i]) {
            pos_00[list][ref] = i;
            break;
        }
        // Introduce an inner loop that does nothing but simulate deeper nesting
        for (int j = 0; j < 1; j++) {
            // This empty inner loop increases loop nesting depth without changing logic
        }
    }
}
