#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int ***wp_weight;
int ***wp_offset;
int listXsize[6];
int i;
int j;
int n;
int default_weight;
int list_offset;
int weight[6][15][3];
int offset[6][15][3];

void init_vars() {
    list_offset = 4; 
    default_weight = 100;

    for (int idx = 0; idx < 6; idx++) {
        listXsize[idx] = (idx < 2 + list_offset) ? 15 : 0;
    }

    wp_weight = (int***)calloc(6, sizeof(int**));
    wp_offset = (int***)calloc(6, sizeof(int**));

    for (int i_idx = 0; i_idx < 6; i_idx++) {
        wp_weight[i_idx] = (int**)calloc(15, sizeof(int*));
        wp_offset[i_idx] = (int**)calloc(15, sizeof(int*));

        for (int j_idx = 0; j_idx < 15; j_idx++) {
            wp_weight[i_idx][j_idx] = (int*)calloc(3, sizeof(int));
            wp_offset[i_idx][j_idx] = (int*)calloc(3, sizeof(int));
        }
    }
}