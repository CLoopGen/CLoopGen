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
for (k = 1 , l = 1; l <= (((1) > (search_range)) ? (1) : (search_range)); l++) {
    for (i = -l + 1; i < l; i++) {
        if (i == 0) continue;
        spiral_search_x[k] = i;
        spiral_search_y[k++] = -l;
        spiral_search_x[k] = i;
        spiral_search_y[k++] = l;
    }
    for (i = -l; i <= l; i++) {
        spiral_search_x[k] = -l;
        spiral_search_y[k++] = i;
        spiral_search_x[k] = l;
        spiral_search_y[k++] = i;
    }
}
}
