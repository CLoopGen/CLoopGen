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
            if (i == 0 || j == 0) {
                lcs[(j) + ((i) * (blen + 1))] = 0;
            } else if (a[i - 1] == b[j - 1]) {
                lcs[(j) + ((i) * (blen + 1))] = lcs[(j - 1) + ((i - 1) * (blen + 1))] + 1;
            } else {
                uint32_t lcs1 = lcs[(j) + ((i - 1) * (blen + 1))];
                uint32_t lcs2 = lcs[(j - 1) + ((i) * (blen + 1))];
                lcs[(j) + ((i) * (blen + 1))] = lcs1 > lcs2 ? lcs1 : lcs2;
            }
        }
    }
}
