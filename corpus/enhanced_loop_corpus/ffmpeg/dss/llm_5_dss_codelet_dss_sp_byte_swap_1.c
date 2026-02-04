#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 3; i < 42; i += 2) {
        if (src[i] != 0) {
            dst[i] = src[i];
        } else {
            dst[i] = 42;
        }
    }
}
