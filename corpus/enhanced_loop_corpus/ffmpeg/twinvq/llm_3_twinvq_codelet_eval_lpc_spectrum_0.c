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
    // Variant 2: Strided memory access with reverse traversal
    int stride = 4;
    for (j = (order - 1) & ~1; j >= 0; j -= stride) {
        int idx0 = j;
        int idx1 = j + 1 < order ? j + 1 : j;  // clamp to valid index
        int idx2 = j - 2 >= 0 ? j - 2 : 0;
        int idx3 = j - 1 >= 0 ? j - 1 : 0;

        q *= lsp[idx0] - two_cos_w;
        p *= lsp[idx1] - two_cos_w;
        if (j >= 2) {
            q *= lsp[idx2] - two_cos_w;
            p *= lsp[idx3] - two_cos_w;
        }
    }
}
