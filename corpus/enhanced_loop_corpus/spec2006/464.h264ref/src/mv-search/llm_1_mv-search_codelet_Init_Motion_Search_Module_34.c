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
    for (i = -l + 1; i < l; i += 2) {
        for (int j = 0; j < 2 && (k + j) <= (((1) > (search_range)) ? (1) : (search_range)) * 8; j++) {
            spiral_search_x[k] = i + j;
            spiral_search_y[k++] = -l;
        }
        for (int j = 0; j < 2 && (k + j) <= (((1) > (search_range)) ? (1) : (search_range)) * 8; j++) {
            spiral_search_x[k] = i + j;
            spiral_search_y[k++] = l;
        }
    }
    for (i = -l; i <= l; i += 2) {
        for (int j = 0; j < 2 && (k + j) <= (((1) > (search_range)) ? (1) : (search_range)) * 8; j++) {
            spiral_search_x[k] = -l;
            spiral_search_y[k++] = i + j;
        }
        for (int j = 0; j < 2 && (k + j) <= (((1) > (search_range)) ? (1) : (search_range)) * 8; j++) {
            spiral_search_x[k] = l;
            spiral_search_y[k++] = i + j;
        }
    }
}
}
