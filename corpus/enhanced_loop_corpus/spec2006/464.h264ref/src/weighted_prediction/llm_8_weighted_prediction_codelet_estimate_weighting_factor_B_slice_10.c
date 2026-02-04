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
for (i = 0; i < listXsize[0]; i++) {
    for (j = 0; j < listXsize[1]; j++) {
        log_weight_denom = luma_log_weight_denom;
        wbp_weight[0][i][j][0] = wp_weight[0][i][0];
        wbp_weight[1][i][j][0] = wp_weight[1][j][0];
        log_weight_denom = chroma_log_weight_denom;
        for (comp = 1; comp < 3; comp++) {
            wbp_weight[0][i][j][comp] = wp_weight[0][i][comp] + wbp_weight[0][i][j][comp-1];
            wbp_weight[1][i][j][comp] = wp_weight[1][j][comp] + wbp_weight[1][i][j][comp-1];
        }
    }
}
}
