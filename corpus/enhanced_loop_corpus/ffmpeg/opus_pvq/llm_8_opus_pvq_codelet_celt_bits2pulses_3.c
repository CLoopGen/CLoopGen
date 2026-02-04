#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *cache;
extern int bits;
extern int i;
extern int low;
extern int high;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 12; i += 2) {
    int center = (low + high + 1) >> 1;
    int offset = (bits - cache[center]) > 0 ? 1 : 0;
    if (cache[center] >= bits)
        high = center - offset;
    else
        low = center + offset;
}
}
