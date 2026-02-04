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
for (i = 2; i < 10; i += 1) {
    int16_t diff_prev = lsp[i-1] - lsp[i-2];
    int16_t diff_next = lsp[i] - lsp[i-1];
    min = (diff_prev > diff_next) ? diff_next : diff_prev;
    if (min > 32)
        weight[i-1] = (1 << 20) / min;
    else
        weight[i-1] = (32767);
}
}
