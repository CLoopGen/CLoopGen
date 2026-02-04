#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ***wp_weight;
int ***wp_offset;
int listXsize[6];
int _usr_index;
int default_weight[3] = {1, 2, 3};
int list_offset = 0;
int clist;

#define index _usr_index

void init_vars() {
    list_offset = 1;
    for (int i = 0; i < 6; i++) {
        listXsize[i] = (i < 3) ? (1 << 16) / (1 << i) : 0;
    }

    wp_weight = (int***)calloc(3, sizeof(int**));
    wp_offset = (int***)calloc(3, sizeof(int**));

    for (int c = 0; c < 3; c++) {
        int size = listXsize[c];
        wp_weight[c] = (int**)calloc(size, sizeof(int*));
        wp_offset[c] = (int**)calloc(size, sizeof(int*));

        for (int i = 0; i < size; i++) {
            wp_weight[c][i] = (int*)calloc(3, sizeof(int));
            wp_offset[c][i] = (int*)calloc(3, sizeof(int));
        }
    }
}