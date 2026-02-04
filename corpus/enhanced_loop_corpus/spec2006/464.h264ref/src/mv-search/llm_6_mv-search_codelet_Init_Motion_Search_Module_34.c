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
    int k1 = 1, l1 = 1;
    for (l1 = 1; l1 <= (((1) > (search_range)) ? (1) : (search_range)); l1++) {
        for (int i1 = -l1 + 1; i1 < l1; i1++) {
            spiral_search_x[k1] = i1;
            spiral_search_y[k1] = -l1;
            k1++;
            spiral_search_x[k1] = i1;
            spiral_search_y[k1] = l1;
            k1++;
        }
        for (int i2 = -l1; i2 <= l1; i2++) {
            spiral_search_x[k1] = -l1;
            spiral_search_y[k1] = i2;
            k1++;
            spiral_search_x[k1] = l1;
            spiral_search_y[k1] = i2;
            k1++;
        }
    }
    k = k1;
}
