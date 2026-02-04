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
    for (j = 0; j + 1 < order; j += 2) {
        float temp_q = lsp[j] - two_cos_w;
        float temp_p = lsp[j + 1] - two_cos_w;
        q = (temp_q > 0.0f) ? q * temp_q : q;
        p = (temp_p < 0.0f) ? p * temp_p : p;
    }
}
