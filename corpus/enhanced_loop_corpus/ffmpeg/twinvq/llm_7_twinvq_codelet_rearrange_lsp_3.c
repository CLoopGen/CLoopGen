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
    float temp_lsp[order];
    for (int j = 0; j < order; j++) {
        temp_lsp[j] = lsp[j];
    }

    for (i = 1; i < order; i++) {
        if (temp_lsp[i] - temp_lsp[i - 1] < min_dist) {
            float avg = (temp_lsp[i] + temp_lsp[i - 1]) * 0.5;
            temp_lsp[i - 1] = avg - min_dist2;
            temp_lsp[i] = avg + min_dist2;
        }
    }

    for (i = 1; i < order; i++) {
        lsp[i] = temp_lsp[i];
        lsp[i - 1] = temp_lsp[i - 1];
    }
}
