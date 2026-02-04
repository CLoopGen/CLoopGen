#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int32_t lsp[16];
extern int32_t pol[16];
extern int half_order;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < half_order; i += 2) {
    if (i + 1 < half_order) {
        pol[i + 2] = pol[i] * 2 - (((((int64_t)(lsp[2 * i]) * (int64_t)(pol[i + 1])) >> 15) + 1) >> 1);
    }
    for (j = i + 1; j > 1; j--)
        pol[j] += pol[j - 2] - (((((int64_t)(lsp[2 * i]) * (int64_t)(pol[j - 1])) >> 15) + 1) >> 1);
    pol[1] -= lsp[2 * i];
    if (i + 1 < half_order) {
        pol[1] -= lsp[2 * (i + 1)];
    }
}
}
