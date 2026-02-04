#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *decoded;
extern int order;
extern int len;
extern int i;
extern int ebps;
extern unsigned int sigma;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 1; j++)
        for (i = order; i < len; i++)
            sigma |= decoded[i] + ebps;
}
