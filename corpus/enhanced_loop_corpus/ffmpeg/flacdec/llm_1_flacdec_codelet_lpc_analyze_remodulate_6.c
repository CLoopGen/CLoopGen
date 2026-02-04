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
        for (i = order; i < len; i += 2) {
            sigma |= decoded[i] + ebps;
            if (i + 1 < len)
                sigma |= decoded[i + 1] + ebps;
        }
    }
}
