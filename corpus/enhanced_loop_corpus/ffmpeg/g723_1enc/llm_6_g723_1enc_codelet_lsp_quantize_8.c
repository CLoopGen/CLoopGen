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
    int16_t temp[10];
    for (i = 0; i < 10; i++) {
        temp[i] = prev_lsp[i] - dc_lsp[i];
    }
    for (i = 0; i < 10; i++) {
        lsp[i] -= dc_lsp[i] + ((temp[i] * 12288 + (1 << 14)) >> 15);
    }
}
