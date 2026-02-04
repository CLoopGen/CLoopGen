#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint16_t u16;
    uint8_t u8[2];
} av_alias16;

extern uint8_t **a;
extern int n;
extern int val;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < (4); n++) {
        (*a)[((4) + n) * 2] = (uint8_t)(val & 0xFF);
        (*a)[((4) + n) * 2 + 1] = (uint8_t)((val >> 8) & 0xFF);
    }
}
