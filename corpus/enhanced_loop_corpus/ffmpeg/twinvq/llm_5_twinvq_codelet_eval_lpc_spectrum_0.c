#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *lsp;
extern int order;
extern int j;
extern float p;
extern float q;
extern float two_cos_w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j + 1 < order; j += 2 * 2) {
        float diff1 = lsp[j] - two_cos_w;
        float diff2 = lsp[j + 1] - two_cos_w;
        q *= (diff1 > 0.0f) ? diff1 : 1.0f;
        p *= (diff2 > 0.0f) ? diff2 : 1.0f;

        if (j + 2 >= order) continue;
        float diff3 = lsp[j + 2] - two_cos_w;
        q *= (diff3 > 0.0f) ? diff3 : 1.0f;

        if (j + 3 >= order) continue;
        float diff4 = lsp[j + 3] - two_cos_w;
        p *= (diff4 > 0.0f) ? diff4 : 1.0f;
    }
}
