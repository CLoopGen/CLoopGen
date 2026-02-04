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
    uint32_t temp = sigma;
    for (i = order; i < len; i++)
        temp |= decoded[i] + ebps;
    sigma = temp;
}
