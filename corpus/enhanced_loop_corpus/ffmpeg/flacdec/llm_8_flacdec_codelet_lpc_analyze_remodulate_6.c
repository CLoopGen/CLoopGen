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
    for (i = order; i < len; i += 2) {
        if (i + 1 < len) {
            sigma |= (decoded[i] + ebps) ^ (decoded[i + 1] + ebps);
        } else {
            sigma |= decoded[i] + ebps;
        }
    }
}
