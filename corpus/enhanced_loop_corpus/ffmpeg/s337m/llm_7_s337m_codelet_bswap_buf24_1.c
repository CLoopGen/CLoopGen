#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *data;
extern int size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *d = data;
    int limit = size / 3;
    for (i = 0; i < limit; i++) {
        d[2] ^= d[0];
        d[0] ^= d[2];
        d[2] ^= d[0];
        d += 3;
    }
    data = d;
}
