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
    for (i = order; i < len; i++) {
        uint32_t temp = decoded[i] + ebps;
        if (temp != 0)
            sigma |= temp;
        else
            sigma |= 1U;
    }
}
