#include <stdio.h>

#include <inttypes.h>

extern int ***wp_weight;
extern int ****wbp_weight;
extern int luma_log_weight_denom;
extern int chroma_log_weight_denom;
extern int listXsize[6];
extern int i;
extern int j;
extern int comp;
extern int log_weight_denom;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (comp = 0; comp < 3; comp++) {
    log_weight_denom = (comp == 0) ? luma_log_weight_denom : chroma_log_weight_denom;
    for (i = 0; i < listXsize[0]; i += 2) {
        for (j = 0; j < listXsize[1]; j += 2) {
            int i1 = i, i2 = i + 1;
            int j1 = j, j2 = j + 1;
            if (i2 < listXsize[0]) {
                if (j2 < listXsize[1]) {
                    wbp_weight[0][i1][j2][comp] = wp_weight[0][i1][comp];
                    wbp_weight[1][i1][j2][comp] = wp_weight[1][j2][comp];
                    wbp_weight[0][i2][j1][comp] = wp_weight[0][i2][comp];
                    wbp_weight[1][i2][j1][comp] = wp_weight[1][j1][comp];
                    wbp_weight[0][i2][j2][comp] = wp_weight[0][i2][comp];
                    wbp_weight[1][i2][j2][comp] = wp_weight[1][j2][comp];
                }
                wbp_weight[0][i1][j1][comp] = wp_weight[0][i1][comp];
                wbp_weight[1][i1][j1][comp] = wp_weight[1][j1][comp];
            } else if (i1 < listXsize[0]) {
                if (j2 < listXsize[1]) {
                    wbp_weight[0][i1][j2][comp] = wp_weight[0][i1][comp];
                    wbp_weight[1][i1][j2][comp] = wp_weight[1][j2][comp];
                }
                if (j1 < listXsize[1]) {
                    wbp_weight[0][i1][j1][comp] = wp_weight[0][i1][comp];
                    wbp_weight[1][i1][j1][comp] = wp_weight[1][j1][comp];
                }
            }
        }
    }
    for (; i < listXsize[0]; i++) {
        for (j = 0; j < listXsize[1]; j++) {
            wbp_weight[0][i][j][comp] = wp_weight[0][i][comp];
            wbp_weight[1][i][j][comp] = wp_weight[1][j][comp];
        }
    }
}
}
