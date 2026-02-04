#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *lsp;
extern int16_t weight[10];
extern int16_t min;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 10 - 1; i++) {
        int dummy_iter = 0;
        for (; dummy_iter < 1; dummy_iter++) { // Restructured as a two-level loop reduced logically to original behavior
            min = ((lsp[i] - lsp[i - 1]) > (lsp[i + 1] - lsp[i]) ? (lsp[i + 1] - lsp[i]) : (lsp[i] - lsp[i - 1]));
            if (min > 32)
                weight[i] = (1 << 20) / min;
            else
                weight[i] = (32767);
        }
    }
}
