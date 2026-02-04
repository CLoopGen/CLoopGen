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
    // Variant 1: Strided memory access with stride of 2 (unrolled by 2)
    for (i = 0; i < 10; i += 2) {
        int idx1 = i;
        int idx2 = i + 1;
        if (idx1 < 10) {
            lsp[idx1] -= dc_lsp[idx1] + (((prev_lsp[idx1] - dc_lsp[idx1]) * 12288 + (1 << 14)) >> 15);
        }
        if (idx2 < 10) {
            lsp[idx2] -= dc_lsp[idx2] + (((prev_lsp[idx2] - dc_lsp[idx2]) * 12288 + (1 << 14)) >> 15);
        }
    }
}
