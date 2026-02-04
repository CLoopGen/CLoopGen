#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int *spiral_search_x;
int *spiral_search_y;
int **pos_00;
short ref;
int list;
int ref_x;
int ref_y;
int pos;
int max_pos;

void init_vars() {
    max_pos = 1 << 20;
    list = 0;
    ref = 0;
    ref_x = -1;
    ref_y = -1;
    pos = 0;

    spiral_search_x = (int*)calloc(max_pos, sizeof(int));
    spiral_search_y = (int*)calloc(max_pos, sizeof(int));

    pos_00 = (int**)calloc(1, sizeof(int*));
    pos_00[list] = (int*)calloc(32768, sizeof(int));

    for (int i = 0; i < max_pos; i++) {
        spiral_search_x[i] = i + 10;
        spiral_search_y[i] = i + 10;
    }

    ref_x = max_pos / 2 + 10;
    ref_y = max_pos / 2 + 10;
}