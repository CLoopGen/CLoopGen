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
    for (i = 0; i < subbands; i++) {
        if (t1[i] >= 0) {
            out[i] = t1[i] >> (15 - 15);
        } else {
            out[i] = 0;
        }
    }
}
