#include <stdio.h>

#include <inttypes.h>

extern  uint8_t doit[];
extern size_t algs_len;
extern size_t i;
extern int maxcnt;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (access every 2nd element first, then handle remainder)
    size_t stride = 2;
    size_t offset;

    // First pass: strided access with step size 2
    for (i = 0; i < algs_len; i += stride) {
        if (maxcnt < doit[i])
            maxcnt = doit[i];
    }

    // Second pass: handle the odd-indexed elements (offset by 1)
    for (offset = 1; offset < stride && offset < algs_len; offset++) {
        for (i = offset; i < algs_len; i += stride) {
            if (maxcnt < doit[i])
                maxcnt = doit[i];
        }
    }
}
