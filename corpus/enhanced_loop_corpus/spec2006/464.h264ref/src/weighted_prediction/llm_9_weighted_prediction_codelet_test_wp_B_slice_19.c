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
int stride = 2;
for (i = 0; i < listXsize[0]; i += stride) {
    for (j = 0; j < listXsize[1]; j += stride) {
        for (comp = 0; comp < 3; comp++) {
            log_weight_denom = (comp == 0) ? luma_log_weight_denom : chroma_log_weight_denom;
            wbp_weight[1][i][j][comp] = im_weight[1][i][j][comp] + (im_weight[1][i][j][comp] >> log_weight_denom);
            if (i + 1 < listXsize[0]) {
                wbp_weight[1][i+1][j][comp] = im_weight[1][i+1][j][comp] + (im_weight[1][i+1][j][comp] >> log_weight_denom);
            }
            if (j + 1 < listXsize[1]) {
                wbp_weight[1][i][j+1][comp] = im_weight[1][i][j+1][comp] + (im_weight[1][i][j+1][comp] >> log_weight_denom);
            }
            if (i + 1 < listXsize[0] && j + 1 < listXsize[1]) {
                wbp_weight[1][i+1][j+1][comp] = im_weight[1][i+1][j+1][comp] + (im_weight[1][i+1][j+1][comp] >> log_weight_denom);
            }

            wbp_weight[0][i][j][comp] = im_weight[0][i][j][comp];
            if (i + 1 < listXsize[0]) {
                wbp_weight[0][i+1][j][comp] = im_weight[0][i+1][j][comp];
            }
            if (j + 1 < listXsize[1]) {
                wbp_weight[0][i][j+1][comp] = im_weight[0][i][j+1][comp];
            }
            if (i + 1 < listXsize[0] && j + 1 < listXsize[1]) {
                wbp_weight[0][i+1][j+1][comp] = im_weight[0][i+1][j+1][comp];
            }
        }
    }
}
}
