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
    if (order < len) {
        sigma = decoded[order] + ebps;
        for (i = order + 1; i < len; i++)
            sigma |= decoded[i] + ebps;
    }
}
