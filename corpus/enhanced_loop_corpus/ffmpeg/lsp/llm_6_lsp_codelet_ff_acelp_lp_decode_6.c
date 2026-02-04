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
    int16_t temp[20];
    for (i = 0; i < lp_order; i++) {
        temp[i] = lsp_2nd[i] + lsp_prev[i];
    }
    for (i = 0; i < lp_order; i++) {
        lsp_1st[i] = temp[i] >> 1;
    }
}
