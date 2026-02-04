#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int ***wp_weight;
int ***wp_offset;
int listXsize[6];
int i;
int j;
int n;
int default_weight[3] = {1, 2, 3};
int list_offset = 0;
int weight[2][15][3];
int offset[2][15][3];

void init_vars() {
    list_offset = 0;

    for (int idx = 0; idx < 6; idx++) {
        listXsize[idx] = (idx < 2) ? 15 : 0;
    }

    wp_weight = (int***)calloc(2 + list_offset, sizeof(int**));
    wp_offset = (int***)calloc(2 + list_offset, sizeof(int**));

    for (i = 0; i < 2 + list_offset; i++) {
        wp_weight[i] = (int**)calloc(listXsize[i], sizeof(int*));
        wp_offset[i] = (int**)calloc(listXsize[i], sizeof(int*));
        for (j = 0; j < listXsize[i]; j++) {
            wp_weight[i][j] = (int*)calloc(3, sizeof(int));
            wp_offset[i][j] = (int*)calloc(3, sizeof(int));
        }
    }
}