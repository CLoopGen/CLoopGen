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
    // Reverse loop order to change data access pattern and introduce WAR dependencies
    // Loop is now ordered by component first, then j, then i — changes locality and dependency flow
    for (comp = 0; comp < 3; comp++) {
        log_weight_denom = (comp == 0) ? luma_log_weight_denom : chroma_log_weight_denom;
        for (j = listXsize[1] - 1; j >= 0; j--) {
            for (i = listXsize[0] - 1; i >= 0; i--) {
                // Write-after-read: wbp_weight is written after being potentially read in later iterations (reversed)
                // This creates a loop-carried WAR hazard if subsequent logic depends on write order
                wbp_weight[0][i][j][comp] = wp_weight[0][i][comp];
                wbp_weight[1][i][j][comp] = wp_weight[1][j][comp];
            }
        }
    }
}
