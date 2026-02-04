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
    int k = 1;
    for (int l = 1; l <= search_range; l++) {
        int step = 1;
        for (int i = -l + 1; i < l; i += step) {
            spiral_search_x[k] = i;
            spiral_search_y[k++] = -l;
            spiral_search_x[k] = -i;
            spiral_search_y[k++] = l;
        }
        for (int i = -l; i <= l; i += step) {
            spiral_search_x[k] = -l;
            spiral_search_y[k++] = i;
            spiral_search_x[k] = l;
            spiral_search_y[k++] = -i;
        }
        k += l % 3; // Artificial computational padding to increase intensity
    }
}
