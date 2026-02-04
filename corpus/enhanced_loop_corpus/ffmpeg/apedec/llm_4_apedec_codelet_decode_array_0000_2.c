#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *out;
extern int blockstodecode;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < blockstodecode; i++) {
        int32_t val = out[i];
        int32_t shifted = val >> 1;
        int32_t lsb = val & 1;
        if (!(lsb)) {
            out[i] = shifted ^ (-1) + 1;
        } else {
            out[i] = shifted ^ 0 + 1;
        }
    }
}
