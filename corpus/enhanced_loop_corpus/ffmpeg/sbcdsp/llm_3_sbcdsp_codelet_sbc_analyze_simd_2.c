#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int subbands;
extern int32_t t1[8];
extern int16_t t2[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    int offset = 1;
    for (i = 0; i < subbands; i++) {
        int index = (i * stride + offset) % subbands;
        t2[index] = t1[index] >> 16;
    }
}
