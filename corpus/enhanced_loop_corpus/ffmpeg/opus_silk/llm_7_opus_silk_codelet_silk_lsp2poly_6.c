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
int32_t prev_pol1 = pol[1];
for (i = 1; i < half_order; i++) {
    int32_t new_val = pol[i - 1] * 2 - (((((int64_t)(lsp[2 * i]) * (int64_t)(pol[i])) >> 15) + 1) >> 1);
    pol[i + 1] = new_val;

    for (j = i; j > 1; j--) {
        int32_t update_term = (((((int64_t)(lsp[2 * i]) * (int64_t)(pol[j - 1])) >> 15) + 1) >> 1);
        pol[j] += pol[j - 2] - update_term;
    }

    prev_pol1 = prev_pol1 - lsp[2 * i];
    pol[1] = prev_pol1;
}
}
