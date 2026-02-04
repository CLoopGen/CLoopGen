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
int list_offset = 1;
int weight[6][15][3];
int offset[6][15][3];

void init_vars() {
    const int outer_dim = 2 + list_offset; 
    const int mid_dim = 15; 
    const int inner_dim = 3;

    for (int idx = 0; idx < 6; idx++) {
        listXsize[idx] = (idx < outer_dim) ? mid_dim : 0;
    }

    wp_weight = (int***)calloc(outer_dim, sizeof(int**));
    wp_offset = (int***)calloc(outer_dim, sizeof(int**));

    for (int i_idx = 0; i_idx < outer_dim; i_idx++) {
        wp_weight[i_idx] = (int**)calloc(mid_dim, sizeof(int*));
        wp_offset[i_idx] = (int**)calloc(mid_dim, sizeof(int*));

        for (int j_idx = 0; j_idx < mid_dim; j_idx++) {
            wp_weight[i_idx][j_idx] = (int*)calloc(inner_dim, sizeof(int));
            wp_offset[i_idx][j_idx] = (int*)calloc(inner_dim, sizeof(int));
        }
    }
}