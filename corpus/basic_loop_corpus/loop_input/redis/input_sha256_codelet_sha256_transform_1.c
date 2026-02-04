#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef uint32_t WORD;

WORD i;
WORD m[64];

void init_vars() {
    i = 16;
    for (int j = 0; j < 64; ++j) {
        if (j < 16) {
            m[j] = (WORD)rand();
        } else {
            m[j] = 0;
        }
    }
}