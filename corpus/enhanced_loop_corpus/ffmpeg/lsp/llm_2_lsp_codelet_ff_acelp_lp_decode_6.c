#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t *lsp_2nd;
extern  int16_t *lsp_prev;
extern int lp_order;
extern int16_t lsp_1st[20];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, processing even indices only
    for (i = 0; i < lp_order; i += 2) {
        if (i < lp_order) {
            lsp_1st[i] = (lsp_2nd[i] + lsp_prev[i]) >> 1;
        }
        int j = i + 1;
        if (j < lp_order) {
            lsp_1st[j] = (lsp_2nd[j] + lsp_prev[j]) >> 1;
        }
    }
}
