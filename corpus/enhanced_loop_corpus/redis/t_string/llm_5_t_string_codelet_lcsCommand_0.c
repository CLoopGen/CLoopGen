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
        for (uint32_t j = 0; j <= blen; j++) {
            uint32_t index = j + i * (blen + 1);
            if (i == 0 || j == 0) {
                lcs[index] = 0;
                continue;
            }
            uint32_t prev_index_diag = (j - 1) + (i - 1) * (blen + 1);
            uint32_t prev_index_up = j + (i - 1) * (blen + 1);
            uint32_t prev_index_left = (j - 1) + i * (blen + 1);

            if (a[i - 1] == b[j - 1]) {
                lcs[index] = lcs[prev_index_diag] + 1;
            } else {
                uint32_t lcs1 = lcs[prev_index_up];
                uint32_t lcs2 = lcs[prev_index_left];
                lcs[index] = (lcs1 > lcs2) ? lcs1 : lcs2;
            }
        }
    }
}
