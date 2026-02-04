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
    float prev_q = q;
    float prev_p = p;
    for (j = 0; j + 1 < order; j += 2 * 2) {
        float diff = lsp[j] - two_cos_w;
        q = (prev_q * diff) * (lsp[j + 2] - two_cos_w);
        p = (prev_p * (lsp[j + 1] - two_cos_w)) * (lsp[j + 3] - two_cos_w);
        prev_q = q;
        prev_p = p;
    }
}
