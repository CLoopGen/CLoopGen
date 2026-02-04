#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int order;
extern float *lsp;
extern float min_dist;
extern int i;
extern float min_dist2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *lsp_local = lsp;
    int order_local = order;
    float min_dist_local = min_dist;
    float min_dist2_local = min_dist2;
    
    for (i = 1; i < order_local; i++) {
        float diff = lsp_local[i] - lsp_local[i - 1];
        if (diff < min_dist_local) {
            float sum = lsp_local[i] + lsp_local[i - 1];
            float avg = sum * 0.5f;
            lsp_local[i - 1] = avg - min_dist2_local;
            lsp_local[i] = avg + min_dist2_local;
        }
    }
}
