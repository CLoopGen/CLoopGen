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
for (i = 0; i < 10; i++) {
    int16_t diff = prev_lsp[i] - dc_lsp[i];
    if (diff > 0) {
        lsp[i] -= dc_lsp[i] + ((diff * 12288 + (1 << 14)) >> 15);
    } else if (diff < 0) {
        lsp[i] -= dc_lsp[i] + ((diff * 12288 + (1 << 14)) >> 15);
    } else {
        continue;
    }
}
}
