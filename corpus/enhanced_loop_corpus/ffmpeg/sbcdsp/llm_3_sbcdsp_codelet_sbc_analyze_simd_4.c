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
    int32_t *out_ptr = out;
    int32_t *t1_ptr = t1;
    for (i = 0; i < subbands; i++) {
        *out_ptr++ = *t1_ptr++ >> (15 - 15);
    }
}
