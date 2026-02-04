#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *out;
extern unsigned int subbands;
extern int32_t t1[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < subbands; i += 2) {
        if (i + 1 < subbands) {
            out[i + 1] = t1[i + 1] >> (15 - 15);
        }
        out[i] = t1[i] >> (15 - 15);
    }
}
