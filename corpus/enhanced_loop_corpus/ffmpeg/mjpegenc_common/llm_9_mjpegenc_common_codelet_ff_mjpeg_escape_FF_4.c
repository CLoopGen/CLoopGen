#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int size;
extern int i;
extern int ff_count;
extern uint8_t *buf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < size && ff_count < 1000; i++) {
        uint8_t val = buf[i];
        ff_count += (val >> 7) & (val >> 6) & 1; // Equivalent to: increment only if val == 255, using bit ops
    }
}
