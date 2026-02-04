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
    int16_t acc = 0;
    for (i = 0; i < 10; i++) {
        acc += dc_lsp[i];
        lsp[i] = lsp[i] - acc - (((prev_lsp[i] - dc_lsp[i]) * 12288 + (1 << 14)) >> 15);
    }
}
