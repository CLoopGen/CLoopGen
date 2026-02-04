#include <stdio.h>

#include <inttypes.h>

typedef uintmax_t ossl_uintmax_t;

extern int level;
extern ossl_uintmax_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ossl_uintmax_t local_n = n;
    int max_iters = ((int)sizeof(ossl_uintmax_t) * 8 + 4 - 1) / 4;
    int early_exit = 0;

    for (level = 1; level < max_iters; level++) {
        ossl_uintmax_t shifted = local_n >> 4;
        local_n = shifted;

        if (shifted == 0 && !early_exit) {
            early_exit = level;
        }
    }

    if (early_exit) {
        level = early_exit;
    }
}
