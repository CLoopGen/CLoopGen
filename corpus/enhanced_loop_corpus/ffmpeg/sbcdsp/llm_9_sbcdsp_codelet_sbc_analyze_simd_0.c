#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int subbands;
extern int32_t t1[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < subbands * 2; i++) {
        j = i % subbands;
        t1[j] = (t1[j] + (1 << (16 - 1))) >> 1;
    }
}
