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
    for (int j = 0; j < 2; j++) {
        for (i = 1; i < order; i++)
            if (lsp[i] - lsp[i - 1] < min_dist) {
                float avg = (lsp[i] + lsp[i - 1]) * 0.5;
                lsp[i - 1] = avg - min_dist2;
                lsp[i] = avg + min_dist2;
            }
    }
}
