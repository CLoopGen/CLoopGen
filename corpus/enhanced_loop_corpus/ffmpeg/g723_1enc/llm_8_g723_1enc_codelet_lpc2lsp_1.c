#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t bandwidth_expand[10];
extern int16_t *lpc;
extern int16_t *lsp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 5; i++) {
        lsp[i] = (lpc[i] * bandwidth_expand[i] + (1 << 14)) >> 15;
        lsp[i + 5] = (lpc[i + 5] * bandwidth_expand[i + 5] + (1 << 14)) >> 15;
    }
}
