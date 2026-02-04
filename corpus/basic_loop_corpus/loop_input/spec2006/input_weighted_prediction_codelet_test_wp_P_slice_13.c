#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int ***wp_weight;
int ***wp_offset;
int listXsize[6];
int i;
int j;
int n;
int default_weight = 1;
int list_offset = 1;

int weight[2][15][3];
int offset[2][15][3];

void init_vars() {
    default_weight = 1;
    list_offset = 1;
    
    for (int idx = 0; idx < 6; idx++) {
        listXsize[idx] = (idx < 3) ? 15 : 0;
    }

    int total_size = 1 << 20; 
    int outer_dim = 2 + list_offset; 
    int inner_j_dim = total_size / (outer_dim * 3);
    
    if (inner_j_dim > 15) inner_j_dim = 15;
    
    for (int idx = 0; idx < outer_dim; idx++) {
        listXsize[idx] = inner_j_dim;
    }

    wp_weight = (int***)calloc(outer_dim, sizeof(int**));
    wp_offset = (int***)calloc(outer_dim, sizeof(int**));

    for (int idx_i = 0; idx_i < outer_dim; idx_i++) {
        wp_weight[idx_i] = (int**)calloc(listXsize[idx_i], sizeof(int*));
        wp_offset[idx_i] = (int**)calloc(listXsize[idx_i], sizeof(int*));

        for (int idx_j = 0; idx_j < listXsize[idx_i]; idx_j++) {
            wp_weight[idx_i][idx_j] = (int*)calloc(3, sizeof(int));
            wp_offset[idx_i][idx_j] = (int*)calloc(3, sizeof(int));
        }
    }
}