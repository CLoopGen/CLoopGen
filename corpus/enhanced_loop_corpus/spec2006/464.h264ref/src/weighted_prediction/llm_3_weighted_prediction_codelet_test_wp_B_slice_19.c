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
    // Variant 2: Use strided memory access by iterating j in reverse and accessing im_weight with a fixed offset pattern
    for (i = 0; i < listXsize[0]; i++) {
        for (j = listXsize[1] - 1; j >= 0; j--) {  // Reverse iteration on j (strided access)
            for (comp = 0; comp < 3; comp++) {
                log_weight_denom = (comp == 0) ? luma_log_weight_denom : chroma_log_weight_denom;
                // Access im_weight with same indices but due to reverse j, access pattern becomes non-sequential
                wbp_weight[1][i][j][comp] = im_weight[1][i][j][comp];
                wbp_weight[0][i][j][comp] = im_weight[0][i][j][comp];
            }
        }
    }
}
