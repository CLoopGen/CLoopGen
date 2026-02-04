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
    int16_t temp[10];
    for (i = 0; i < 10; i++) {
        temp[i] = lpc[i] * bandwidth_expand[i];
    }
    for (i = 0; i < 10; i++) {
        lsp[i] = (temp[i] + (1 << 14)) >> 15;
    }
}
