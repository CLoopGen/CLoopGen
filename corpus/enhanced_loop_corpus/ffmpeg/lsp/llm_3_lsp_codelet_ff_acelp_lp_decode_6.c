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
    // Variant 2: Reverse sequential access – process array from end to start
    for (i = lp_order - 1; i >= 0; i--) {
        lsp_1st[i] = (lsp_2nd[i] + lsp_prev[i]) >> 1;
    }
}
