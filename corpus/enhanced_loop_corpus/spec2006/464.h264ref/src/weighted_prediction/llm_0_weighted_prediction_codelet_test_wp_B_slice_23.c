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
    for (comp = 0; comp < 3; comp++) {
        wbp_weight[0][i][0][comp] = wp_weight[0][i][comp];
        for (j = 1; j < listXsize[1]; j++) {
            wbp_weight[0][i][j][comp] = wp_weight[0][i][comp];
            wbp_weight[1][i][j][comp] = wp_weight[1][j][comp];
        }
    }
}
}
