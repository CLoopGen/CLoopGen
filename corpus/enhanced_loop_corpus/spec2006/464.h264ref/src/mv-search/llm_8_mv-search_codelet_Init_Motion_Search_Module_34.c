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
    int k = 1, l = 1;
    int max_range = (search_range < 1) ? 1 : search_range;
    for (; l <= max_range; l += 2) {
        int bound = l + 1;
        for (int i = -l + 1; i < bound; i++) {
            if (k >= (max_range * max_range * 4)) break;
            spiral_search_x[k] = i;
            spiral_search_y[k++] = -l;
            if (k >= (max_range * max_range * 4)) break;
            spiral_search_x[k] = i;
            spiral_search_y[k++] = l;
        }
        for (int i = -l; i <= l; i++) {
            if (k >= (max_range * max_range * 4)) break;
            spiral_search_x[k] = -l;
            spiral_search_y[k++] = i;
            if (k >= (max_range * max_range * 4)) break;
            spiral_search_x[k] = l;
            spiral_search_y[k++] = i;
        }
    }
}
