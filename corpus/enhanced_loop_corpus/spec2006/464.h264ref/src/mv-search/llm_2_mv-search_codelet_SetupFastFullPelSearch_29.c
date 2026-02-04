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
    int *sx = spiral_search_x;
    int *sy = spiral_search_y;
    int **p00 = pos_00;
    int r_x = ref_x;
    int r_y = ref_y;
    int l = list;
    short r = ref;

    for (pos = 0; pos < max_pos; pos += 2) {
        if (r_x == sx[pos] && r_y == sy[pos]) {
            p00[l][r] = pos;
            break;
        }
        if (pos + 1 < max_pos && r_x == sx[pos + 1] && r_y == sy[pos + 1]) {
            p00[l][r] = pos + 1;
            break;
        }
    }
}
