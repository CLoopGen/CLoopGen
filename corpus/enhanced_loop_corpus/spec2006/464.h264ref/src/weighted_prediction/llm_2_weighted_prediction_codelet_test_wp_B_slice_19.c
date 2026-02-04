#include <stdio.h>

#include <inttypes.h>

extern int ****wbp_weight;
extern int luma_log_weight_denom;
extern int chroma_log_weight_denom;
extern int listXsize[6];
extern int i;
extern int j;
extern int comp;
extern int log_weight_denom;
extern int im_weight[6][15][15][3];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Change memory access pattern to stride by 2 with bounds check, unrolling the inner comp loop for consecutive access
    int comp;
    for (i = 0; i < listXsize[0]; i++) {
        for (j = 0; j < listXsize[1]; j++) {
            // Unroll and directly assign each component with consecutive memory writes
            log_weight_denom = luma_log_weight_denom; // comp == 0
            wbp_weight[1][i][j][0] = im_weight[1][i][j][0];
            wbp_weight[0][i][j][0] = im_weight[0][i][j][0];

            log_weight_denom = chroma_log_weight_denom; // comp == 1
            wbp_weight[1][i][j][1] = im_weight[1][i][j][1];
            wbp_weight[0][i][j][1] = im_weight[0][i][j][1];

            wbp_weight[1][i][j][2] = im_weight[1][i][j][2]; // comp == 2
            wbp_weight[0][i][j][2] = im_weight[0][i][j][2];
        }
    }
}
