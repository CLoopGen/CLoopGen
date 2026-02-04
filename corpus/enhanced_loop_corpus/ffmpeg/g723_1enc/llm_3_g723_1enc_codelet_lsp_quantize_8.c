#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t dc_lsp[10];
extern int16_t *lsp;
extern int16_t *prev_lsp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (backward traversal)
    for (i = 9; i >= 0; i--) {
        lsp[i] -= dc_lsp[i] + (((prev_lsp[i] - dc_lsp[i]) * 12288 + (1 << 14)) >> 15);
    }
}
