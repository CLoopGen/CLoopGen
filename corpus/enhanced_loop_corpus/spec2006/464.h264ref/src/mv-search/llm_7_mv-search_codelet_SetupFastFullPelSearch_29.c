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
    int found = 0;
    for (pos = 0; pos < max_pos && !found; pos++) {
        int x_val = spiral_search_x[pos];
        int y_val = spiral_search_y[pos];
        int match = (ref_x == x_val && ref_y == y_val);
        if (match) {
            pos_00[list][ref] = pos;
            found = 1;
        }
    }
}
