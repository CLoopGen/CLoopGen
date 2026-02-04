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
        int *wbp0 = &wbp_weight[0][i][j][0];
        int *wbp1 = &wbp_weight[1][i][j][0];
        int *wp0 = &wp_weight[0][i][0];
        int *wp1 = &wp_weight[1][j][0];
        for (comp = 0; comp < 3; comp++) {
            log_weight_denom = (comp == 0) ? luma_log_weight_denom : chroma_log_weight_denom;
            wbp0[comp] = wp0[comp];
            wbp1[comp] = wp1[comp];
        }
    }
}
}
