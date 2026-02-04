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
    for (int outer = 0; outer < order / 4; outer++) {
        for (int inner = 0; inner < 4; inner += 2) {
            int idx = outer * 4 + inner;
            q *= lsp[idx] - two_cos_w;
            p *= lsp[idx + 1] - two_cos_w;
        }
    }
}
