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
for (i = 0; i < 5; i++) {
    int16_t diff1 = prev_lsp[i] - dc_lsp[i];
    int16_t scaled = (diff1 * 8192 + (1 << 13)) >> 14;
    lsp[i] -= dc_lsp[i] + scaled;
    lsp[9-i] -= dc_lsp[9-i] + scaled;
}
}
