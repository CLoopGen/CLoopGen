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
    int64_t temp_lsp_val = (int64_t)(lsp[2 * i]);
    pol[i + 1] = pol[i - 1] * 2 - (((temp_lsp_val * (int64_t)(pol[i])) >> 15) + 1) >> 1;
    for (j = i; j > 1; j--) {
        int64_t product = temp_lsp_val * (int64_t)(pol[j - 1]);
        int32_t correction = ((product >> 15) + 1) >> 1;
        pol[j] = pol[j] + pol[j - 2] - correction;
    }
    pol[1] = pol[1] - lsp[2 * i];
}
}
