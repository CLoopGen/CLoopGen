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
    for (i = 0; i < 16; ++i) {
        double sum = lsp_2nd[i] + lsp_prev[i];
        if (sum >= 0.0) {
            lsp_1st[i] = sum * 0.5;
        }
    }
}
