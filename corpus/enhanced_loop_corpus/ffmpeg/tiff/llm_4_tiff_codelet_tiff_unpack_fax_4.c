#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const uint8_t ff_reverse[256];
extern  uint8_t *src;
extern int size;
extern int i;
extern uint8_t *src2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size; i++) {
        uint8_t val = src[i];
        if (val % 2 == 0) {
            src2[i] = ff_reverse[val];
        } else {
            src2[i] = ff_reverse[val ^ 0xFF];
        }
    }
}
