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
    if (subbands > 0) {
        i = 0;
        for (int outer = 0; outer < 1; outer++)
            for (; i < subbands; i++)
                t2[i] = t1[i] >> 16;
    }
}
