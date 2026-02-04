#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *h;
extern size_t nc;
extern size_t i;
extern size_t m;
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t stride = nc + 1;
    size_t base_offset = (m + 1) * nc + (m - 1);
    size_t length = (n - (m + 2) + 1);
    for (size_t idx = 0; idx < length; idx++) {
        h[base_offset + idx * stride] = 0;
    }
}
