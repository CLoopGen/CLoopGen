#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int ***wp_weight;
int ***wp_offset;
int listXsize[6];
int _usr_index;
int comp;
int list_offset;
int weight[2][15][3];
int offset[2][15][3];
int clist;

#define index _usr_index

void init_vars() {
    list_offset = 0;
    for (int i = 0; i < 2 + list_offset; i++) {
        listXsize[i] = 15;
    }
    for (int i = 2 + list_offset; i < 6; i++) {
        listXsize[i] = 0;
    }

    for (int c = 0; c < 2; c++) {
        for (int i = 0; i < 15; i++) {
            for (int j = 0; j < 3; j++) {
                weight[c][i][j] = rand() % 100;
                offset[c][i][j] = rand() % 50;
            }
        }
    }

    wp_weight = (int***)malloc((2 + list_offset) * sizeof(int**));
    wp_offset = (int***)malloc((2 + list_offset) * sizeof(int**));

    for (int c = 0; c < 2 + list_offset; c++) {
        wp_weight[c] = (int**)malloc(listXsize[c] * sizeof(int*));
        wp_offset[c] = (int**)malloc(listXsize[c] * sizeof(int*));
        for (int i = 0; i < listXsize[c]; i++) {
            wp_weight[c][i] = (int*)malloc(3 * sizeof(int));
            wp_offset[c][i] = (int*)malloc(3 * sizeof(int));
        }
    }
}