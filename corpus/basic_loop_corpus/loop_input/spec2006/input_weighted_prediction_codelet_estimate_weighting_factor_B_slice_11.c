#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

#define LIST_OFFSET 0
#define MAX_CLIST (2 + LIST_OFFSET)
#define MAX_INDEX 15
#define COMP_COUNT 3

int ***wp_weight;
int ***wp_offset;
int listXsize[6];
int _usr_index;
int comp;
int list_offset = LIST_OFFSET;
int weight[6][15][3];
int offset[6][15][3];
int clist;

#define index _usr_index

void init_vars() {
    // Initialize listXsize to valid dimensions within declared arrays
    for (int i = 0; i < MAX_CLIST; i++) {
        listXsize[i] = 15;  // Match second dimension of weight/offset
    }

    // Allocate wp_weight and wp_offset as 3D integer pointer arrays: [6][15][3]
    wp_weight = (int***)calloc(6, sizeof(int**));
    wp_offset = (int***)calloc(6, sizeof(int**));

    for (int i = 0; i < 6; i++) {
        wp_weight[i] = (int**)calloc(15, sizeof(int*));
        wp_offset[i] = (int**)calloc(15, sizeof(int*));

        for (int j = 0; j < 15; j++) {
            wp_weight[i][j] = (int*)calloc(3, sizeof(int));
            wp_offset[i][j] = (int*)calloc(3, sizeof(int));
        }
    }

    // Initialize weight and offset arrays with sample data
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 15; j++) {
            for (int k = 0; k < 3; k++) {
                weight[i][j][k] = i * 1000 + j * 10 + k;
                offset[i][j][k] = i * 500 + j * 5 + k;
            }
        }
    }
}