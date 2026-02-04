#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lsp;
extern int order;
extern int j;
extern float p;
extern float q;
extern float two_cos_w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (order <= 1) return;
    for (j = 0; j + 1 < order; j += 2) {
        float diff1 = lsp[j] - two_cos_w;
        float diff2 = lsp[j + 1] - two_cos_w;
        if (diff1 != 0.0f) {
            q *= diff1;
        }
        if (diff2 != 0.0f) {
            p *= diff2;
        }
    }
}
