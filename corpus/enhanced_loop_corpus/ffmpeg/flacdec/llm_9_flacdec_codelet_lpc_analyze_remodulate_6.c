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
    int step = 1 << (ebps & 3); // Vary stride based on ebps mod 4
    for (i = order; i < len; i += step) {
        uint32_t temp = decoded[i] + ebps;
        sigma ^= temp * temp; // Increase arithmetic intensity with square and XOR
    }
}
