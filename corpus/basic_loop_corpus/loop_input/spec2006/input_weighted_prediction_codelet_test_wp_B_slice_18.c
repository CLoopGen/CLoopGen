#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int ***wp_weight;
int ***wp_offset;
int listXsize[6];
int _usr_index;
int comp;
int default_weight;
int list_offset;
int clist;
int perform_wp;

#define index _usr_index

void init_vars() {
    list_offset = 0;
    default_weight = 1;
    perform_wp = 0;

    const int depth1 = 2 + list_offset; 
    const int max_depth2 = 512;
    const int depth3 = 3;

    wp_weight = (int***)calloc(depth1, sizeof(int**));
    wp_offset = (int***)calloc(depth1, sizeof(int**));

    for (int i = 0; i < depth1; i++) {
        listXsize[i] = max_depth2;
        wp_weight[i] = (int**)malloc(max_depth2 * sizeof(int*));
        wp_offset[i] = (int**)malloc(max_depth2 * sizeof(int*));
        for (int j = 0; j < max_depth2; j++) {
            wp_weight[i][j] = (int*)malloc(depth3 * sizeof(int));
            wp_offset[i][j] = (int*)malloc(depth3 * sizeof(int));
            for (int k = 0; k < depth3; k++) {
                wp_weight[i][j][k] = default_weight;
                wp_offset[i][j][k] = 0;
            }
        }
    }

    wp_weight[depth1 - 1][max_depth2 - 1][2] = default_weight + 1;
}