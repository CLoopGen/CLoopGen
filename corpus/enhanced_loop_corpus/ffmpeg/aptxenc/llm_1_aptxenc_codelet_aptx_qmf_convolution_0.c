#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int32_t coeffs[16];
extern int32_t *sig;
extern int64_t e;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer, inner;
    for (outer = 0; outer < 4; outer++)
        for (inner = 0; inner < 4; inner++)
            e += ((int64_t)(sig[outer * 4 + inner]) * (int64_t)(coeffs[outer * 4 + inner]));
}
