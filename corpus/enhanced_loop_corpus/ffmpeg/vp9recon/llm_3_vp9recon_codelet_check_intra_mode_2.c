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
    int indices[4] = {10, 12, 14, 16}; // Strided access pattern with step of 2
    for (n = 0; n < (4); n++) {
        (((av_alias16 *)(&(*a)[indices[n]]))->u16 = (val));
    }
}
