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
int j;
for (i = 1; i < 10 - 1; i += 2) {
    for (j = 0; j < 2 && (i + j) < 9; j++) {
        int16_t idx = i + j;
        int16_t left_diff = lsp[idx] - lsp[idx - 1];
        int16_t right_diff = lsp[idx + 1] - lsp[idx];
        min = (left_diff < right_diff) ? left_diff : right_diff;
        if (min > 32)
            weight[idx] = (1 << 19) / (min + 1);
        else
            weight[idx] = 32767;
    }
}
}
