#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int ****wbp_weight;
int luma_log_weight_denom = 8;
int chroma_log_weight_denom = 7;
int listXsize[6] = {5, 5, 0, 0, 0, 0};
int i;
int j;
int comp;
int log_weight_denom;
int im_weight[6][15][15][3];

void init_vars() {
    // Allocate wbp_weight[2][listXsize[0]][listXsize[1]][3]
    wbp_weight = (int ****)calloc(2, sizeof(int ***));
    for (int idx0 = 0; idx0 < 2; idx0++) {
        wbp_weight[idx0] = (int ***)calloc(listXsize[0], sizeof(int **));
        for (int idx1 = 0; idx1 < listXsize[0]; idx1++) {
            wbp_weight[idx0][idx1] = (int **)calloc(listXsize[1], sizeof(int *));
            for (int idx2 = 0; idx2 < listXsize[1]; idx2++) {
                wbp_weight[idx0][idx1][idx2] = (int *)calloc(3, sizeof(int));
            }
        }
    }

    // Initialize im_weight with non-zero values to ensure meaningful data
    for (int a = 0; a < 6; a++) {
        for (int b = 0; b < 15; b++) {
            for (int c = 0; c < 15; c++) {
                for (int d = 0; d < 3; d++) {
                    im_weight[a][b][c][d] = (a + 1) * (b + 1) * (c + 1) * (d + 1);
                }
            }
        }
    }
}