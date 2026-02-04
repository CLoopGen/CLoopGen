#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef char *sds;

extern sds a;
extern sds b;
extern uint32_t alen;
extern uint32_t blen;
extern uint32_t *lcs;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (uint32_t i = 0; i <= alen; i++) {
        uint32_t base_i = i * (blen + 1);
        for (uint32_t j = 0; j <= blen; j++) {
            uint32_t idx = j + base_i;
            if (i == 0 || j == 0) {
                lcs[idx] = 0;
            } else if (a[i - 1] == b[j - 1]) {
                lcs[idx] = lcs[(j - 1) + ((i - 1) * (blen + 1))] + 1;
            } else {
                uint32_t prev_row = lcs[j + ((i - 1) * (blen + 1))];
                uint32_t prev_col = lcs[(j - 1) + base_i];
                lcs[idx] = prev_row > prev_col ? prev_row : prev_col;
            }
        }
    }
}
