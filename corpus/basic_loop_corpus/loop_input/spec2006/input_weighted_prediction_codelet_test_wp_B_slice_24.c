#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

#define index _usr_index

int ***wp_weight;
int ***wp_offset;
int listXsize[6];
int _usr_index;
int comp;
int list_offset;
int weight[6][15][3];
int offset[6][15][3];
int clist;

const int MAX_CLIST = 4;
const int MAX_INDEX = 15;
const int COMP_SIZE = 3;

void init_vars() {
    list_offset = 2;
    
    for (int i = 0; i < 6; i++) {
        listXsize[i] = (i < MAX_CLIST) ? MAX_INDEX : 0;
    }

    for (int c = 0; c < 6; c++) {
        for (int i = 0; i < 15; i++) {
            for (int j = 0; j < 3; j++) {
                weight[c][i][j] = rand() % 1000;
                offset[c][i][j] = rand() % 500;
            }
        }
    }

    wp_weight = (int***)calloc(MAX_CLIST, sizeof(int**));
    wp_offset = (int***)calloc(MAX_CLIST, sizeof(int**));

    for (int c = 0; c < MAX_CLIST; c++) {
        wp_weight[c] = (int**)calloc(MAX_INDEX, sizeof(int*));
        wp_offset[c] = (int**)calloc(MAX_INDEX, sizeof(int*));
        
        for (int i = 0; i < MAX_INDEX; i++) {
            wp_weight[c][i] = (int*)calloc(COMP_SIZE, sizeof(int));
            wp_offset[c][i] = (int*)calloc(COMP_SIZE, sizeof(int));
        }
    }
}