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
    // Variant 1: Strided memory access with stride of 2, processing even indices first, then odd
    for (i = 0; i < 16; i += 2)
        lsp_1st[i] = (lsp_2nd[i] + lsp_prev[i]) * 0.5;
    for (i = 1; i < 16; i += 2)
        lsp_1st[i] = (lsp_2nd[i] + lsp_prev[i]) * 0.5;
}
