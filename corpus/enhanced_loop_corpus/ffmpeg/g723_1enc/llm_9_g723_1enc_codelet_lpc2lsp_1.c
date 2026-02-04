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
    int j;
    for (i = 0; i < 20; i += 2) {
        j = i >> 1;
        lsp[j] = ((lpc[j] * bandwidth_expand[j] + (1 << 13)) * 3 + (1 << 14)) >> 16;
    }
}
