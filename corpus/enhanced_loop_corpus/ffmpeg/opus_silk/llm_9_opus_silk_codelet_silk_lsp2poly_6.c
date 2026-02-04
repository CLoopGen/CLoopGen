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
for (i = 1; i < half_order; i++) {
    int32_t temp = (((((int64_t)(lsp[2 * i]) * (int64_t)(pol[i])) >> 15) + 1) >> 1);
    pol[i + 1] = pol[i - 1] * 2 - temp;
    for (j = i; j > 2; j--) {
        int32_t correction = (((((int64_t)(lsp[2 * i]) * (int64_t)(pol[j - 1])) >> 15) + 1) >> 1);
        pol[j] += pol[j - 2] - correction;
        pol[j - 1] += pol[j - 3] - (((((int64_t)(lsp[2 * i]) * (int64_t)(pol[j - 2])) >> 15) + 1) >> 1);
    }
    if (i >= 2) {
        pol[2] += pol[0] - (((((int64_t)(lsp[2 * i]) * (int64_t)(pol[1])) >> 15) + 1) >> 1);
    }
    pol[1] -= lsp[2 * i];
}
}
