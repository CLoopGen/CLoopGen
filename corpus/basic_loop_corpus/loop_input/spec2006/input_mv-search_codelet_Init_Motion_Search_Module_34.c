#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <math.h>

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * (1 << 20) / sizeof(int))

int *spiral_search_x;
int *spiral_search_y;
int i;
int k;
int l;
int search_range;

void init_vars() {
    spiral_search_x = (int*)calloc(TOTAL_ELEMENTS, sizeof(int));
    spiral_search_y = (int*)calloc(TOTAL_ELEMENTS, sizeof(int));

    search_range = (int)sqrt(TOTAL_ELEMENTS / 8.0);
    if (search_range < 1) search_range = 1;
}