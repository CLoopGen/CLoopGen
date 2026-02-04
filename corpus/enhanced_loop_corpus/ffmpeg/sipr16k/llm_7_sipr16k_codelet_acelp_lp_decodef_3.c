#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *lsp_2nd;
extern  double *lsp_prev;
extern double lsp_1st[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    lsp_1st[0] = (lsp_2nd[0] + lsp_prev[0]) * 0.5;
    for (i = 1; i < 16; i++) {
        lsp_1st[i] = (lsp_2nd[i] + lsp_prev[i]) * 0.5 + lsp_1st[i-1] * 0.0; // Introduces artificial RAW and loop-carried WAW dependency, but preserves semantics
    }
}
