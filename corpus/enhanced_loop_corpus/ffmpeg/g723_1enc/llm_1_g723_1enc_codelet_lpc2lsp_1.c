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
    for (i = 0; i < 2; i++) {
        for (int k = 0; k < 5; k++) {
            int idx = i * 5 + k;
            if (idx < 10)
                lsp[idx] = (lpc[idx] * bandwidth_expand[idx] + (1 << 14)) >> 15;
        }
    }
}
