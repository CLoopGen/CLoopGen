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
    int32_t temp;
    for (i = 0; i < subbands; i++) {
        temp = t1[i] >> (15 - 15);
        out[i] = temp;
    }
}
