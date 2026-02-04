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
    int outer;
    int inner;
    for (outer = 0; outer < bytes / 8; outer++) {
        for (inner = 0; inner < 2; inner++) {
            int idx = outer * 2 + inner;
            output[idx] = c ^ buf[idx];
        }
    }
}
