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
    for (int j = 0; j < 1; j++)
        for (i = 0; i < subbands; i++)
            t2[i] = t1[i] >> 16;
}
