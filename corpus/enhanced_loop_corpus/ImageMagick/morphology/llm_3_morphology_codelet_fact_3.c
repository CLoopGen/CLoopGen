#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t n;
extern size_t f;
extern size_t l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t stride = 2;
    f = 1;
    if (n < 2) return;
    for (l = 2; l <= n; l += stride) {
        f = f * l;
        if (l + 1 <= n) {
            f = f * (l + 1);
        }
    }
}
