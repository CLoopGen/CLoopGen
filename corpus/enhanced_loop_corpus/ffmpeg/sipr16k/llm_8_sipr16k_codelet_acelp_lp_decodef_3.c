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
    for (i = 0; i < 16; i += 2) {
        lsp_1st[i] = (lsp_2nd[i] + lsp_prev[i]) * 0.5;
        if (i + 1 < 16) {
            lsp_1st[i+1] = (lsp_2nd[i+1] + lsp_prev[i+1]) * 0.5;
        }
    }
}
