#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int subbands;
extern int32_t t1[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 1 << (16 - 1);
    for (i = 0; i < subbands; i++)
        t1[i] = temp;
}
