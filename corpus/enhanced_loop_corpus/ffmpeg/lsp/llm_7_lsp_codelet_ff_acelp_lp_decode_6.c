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
    int acc = 0;
    for (i = 0; i < lp_order; i++) {
        acc += (lsp_2nd[i] + lsp_prev[i]) >> 1;
        lsp_1st[i] = acc;
    }
}
