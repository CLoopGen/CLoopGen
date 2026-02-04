#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *lsp;
extern int f[12];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 10 / 2; i++) {
        int16_t sum = lsp[i] + lsp[10 - 1 - i];
        int16_t diff = lsp[i] - lsp[10 - 1 - i];
        int scaled_sum = sum << 12;
        int scaled_diff = diff << 12;
        f[2 * i + 2] = -f[2 * i] - scaled_sum;
        f[2 * i + 3] = f[2 * i + 1] - scaled_diff;
    }
}
