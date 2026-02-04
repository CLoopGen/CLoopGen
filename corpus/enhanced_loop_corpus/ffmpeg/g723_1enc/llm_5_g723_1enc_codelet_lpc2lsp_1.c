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
    for (i = 0; i < 10; ++i) {
        int16_t temp = lpc[i] * bandwidth_expand[i];
        if (temp >= 0) {
            lsp[i] = (temp + (1 << 14)) >> 15;
        } else {
            lsp[i] = (temp - (1 << 14) + 1) >> 15;
        }
    }
}
