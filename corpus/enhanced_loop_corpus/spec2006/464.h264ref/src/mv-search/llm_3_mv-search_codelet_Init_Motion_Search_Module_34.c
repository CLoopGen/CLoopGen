#include <stdio.h>

#include <inttypes.h>

extern int *spiral_search_x;
extern int *spiral_search_y;
extern int i;
extern int k;
extern int l;
extern int search_range;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *x_ptr = spiral_search_x + 1;
    int *y_ptr = spiral_search_y + 1;
    for (k = 1, l = 1; l <= (((1) > (search_range)) ? (1) : (search_range)); l++) {
        for (i = -l + 1; i < l; i++) {
            *(x_ptr++) = i;
            *(y_ptr++) = -l;
            *(x_ptr++) = i;
            *(y_ptr++) = l;
        }
        for (i = -l; i <= l; i++) {
            *(x_ptr++) = -l;
            *(y_ptr++) = i;
            *(x_ptr++) = l;
            *(y_ptr++) = i;
        }
    }
    k = x_ptr - spiral_search_x;
}
