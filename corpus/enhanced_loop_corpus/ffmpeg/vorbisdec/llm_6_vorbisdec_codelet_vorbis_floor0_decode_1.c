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
    float temp_q = q;
    float temp_p = p;
    for (j = 0; j + 1 < order; j += 2) {
        temp_q *= lsp[j] - two_cos_w;
        temp_p *= lsp[j + 1] - two_cos_w;
    }
    q = temp_q;
    p = temp_p;
}
