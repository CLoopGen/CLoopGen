#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int ***wp_weight;
int ****wbp_weight;
int luma_log_weight_denom = 8;
int chroma_log_weight_denom = 8;
int listXsize[6] = {128, 128, 0, 0, 0, 0};
int i;
int j;
int comp;
int log_weight_denom;

void init_vars() {
    // Allocate wp_weight[2][listXsize][3]
    wp_weight = (int***)malloc(2 * sizeof(int**));
    for (int idx0 = 0; idx0 < 2; idx0++) {
        wp_weight[idx0] = (int**)malloc(listXsize[idx0] * sizeof(int*));
        for (int idx1 = 0; idx1 < listXsize[idx0]; idx1++) {
            wp_weight[idx0][idx1] = (int*)calloc(3, sizeof(int));
            for (int c = 0; c < 3; c++) {
                wp_weight[idx0][idx1][c] = (idx0 + 1) * (idx1 + 1) * (c + 1);
            }
        }
    }

    // Allocate wbp_weight[2][listXsize[0]][listXsize[1]][3]
    wbp_weight = (int****)malloc(2 * sizeof(int***));
    for (int idx0 = 0; idx0 < 2; idx0++) {
        wbp_weight[idx0] = (int***)malloc(listXsize[0] * sizeof(int**));
        for (int idx1 = 0; idx1 < listXsize[0]; idx1++) {
            wbp_weight[idx0][idx1] = (int**)malloc(listXsize[1] * sizeof(int*));
            for (int idx2 = 0; idx2 < listXsize[1]; idx2++) {
                wbp_weight[idx0][idx1][idx2] = (int*)calloc(3, sizeof(int));
            }
        }
    }
}