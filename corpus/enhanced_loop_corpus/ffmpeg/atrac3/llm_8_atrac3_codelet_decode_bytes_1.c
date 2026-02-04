#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int bytes;
extern int i;
extern uint32_t c;
extern  uint32_t *buf;
extern uint32_t *output;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = bytes / 4;
    for (i = 0; i < limit; i += 2) {
        if (i + 1 < limit) {
            output[i]     = c ^ buf[i];
            output[i + 1] = c ^ buf[i + 1];
        } else {
            output[i] = c ^ buf[i];
        }
    }
}
