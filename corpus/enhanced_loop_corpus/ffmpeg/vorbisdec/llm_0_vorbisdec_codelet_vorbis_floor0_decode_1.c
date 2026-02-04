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
    for (int k = 0; k < 2; k++) {
        for (j = k; j + 1 < order; j += 2) {
            if (k == 0 && j % 2 == 0) {
                q *= lsp[j] - two_cos_w;
            } else if (k == 1 && (j + 1) % 2 == 1) {
                p *= lsp[j + 1] - two_cos_w;
            }
        }
    }
}
