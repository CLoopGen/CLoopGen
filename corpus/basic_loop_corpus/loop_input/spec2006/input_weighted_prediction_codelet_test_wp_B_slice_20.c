#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int ***wp_weight;
int ***wp_offset;
int luma_log_weight_denom;
int chroma_log_weight_denom;
int listXsize[6];
int _usr_index;
int list_offset;
int clist;

#define index _usr_index

void init_vars() {
    luma_log_weight_denom = 5;
    chroma_log_weight_denom = 4;
    list_offset = 1;

    for (int i = 0; i < 2 + list_offset; i++) {
        listXsize[i] = (1 << 20) / (3 * (2 + list_offset)); // Distribute ~1MB of data
    }

    wp_weight = (int***)calloc(2 + list_offset, sizeof(int**));
    wp_offset = (int***)calloc(2 + list_offset, sizeof(int**));

    for (int clist = 0; clist < 2 + list_offset; clist++) {
        wp_weight[clist] = (int**)calloc(listXsize[clist], sizeof(int*));
        wp_offset[clist] = (int**)calloc(listXsize[clist], sizeof(int*));

        for (int index = 0; index < listXsize[clist]; index++) {
            wp_weight[clist][index] = (int*)calloc(3, sizeof(int));
            wp_offset[clist][index] = (int*)calloc(3, sizeof(int));
        }
    }
}