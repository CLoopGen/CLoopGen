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
    for (i = 0; i < listXsize[0]; i++) {
        for (j = 0; j < listXsize[1]; j++) {
            // Introduce loop-carried dependence by making comp dependent on previous iteration
            int prev_comp = -1;
            for (comp = 0; comp < 3; comp++) {
                log_weight_denom = (comp == 0) ? luma_log_weight_denom : chroma_log_weight_denom;
                // Create a WAW dependency: write before updating same location in next comp if any
                wbp_weight[1][i][j][comp] = im_weight[1][i][j][comp] + (prev_comp == comp - 1 ? wbp_weight[1][i][j][comp-1] : 0);
                wbp_weight[0][i][j][comp] = im_weight[0][i][j][comp];
                prev_comp = comp;
            }
        }
    }
}
