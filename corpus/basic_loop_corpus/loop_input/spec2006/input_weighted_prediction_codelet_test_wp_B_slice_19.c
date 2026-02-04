#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int ****wbp_weight;
int luma_log_weight_denom = 8;
int chroma_log_weight_denom = 7;
int listXsize[6] = {8, 8, 0, 0, 0, 0};
int i;
int j;
int comp;
int log_weight_denom;
int im_weight[6][15][15][3];

static int initialized = 0;

void init_vars() {
    if (initialized) return;
    
    // Allocate wbp_weight[2][listXsize[0]][listXsize[1]][3]
    wbp_weight = (int ****)calloc(2, sizeof(int ***));
    for (int a = 0; a < 2; a++) {
        wbp_weight[a] = (int ***)calloc(listXsize[0], sizeof(int **));
        for (int b = 0; b < listXsize[0]; b++) {
            wbp_weight[a][b] = (int **)calloc(listXsize[1], sizeof(int *));
            for (int c = 0; c < listXsize[1]; c++) {
                wbp_weight[a][b][c] = (int *)calloc(3, sizeof(int));
            }
        }
    }

    // Initialize im_weight with non-zero values to simulate realistic data
    for (int a = 0; a < 6; a++) {
        for (int b = 0; b < 15; b++) {
            for (int c = 0; c < 15; c++) {
                for (int d = 0; d < 3; d++) {
                    im_weight[a][b][c][d] = (a + 1) * (b + 1) * (c + 1) * (d + 1);
                }
            }
        }
    }

    initialized = 1;
}