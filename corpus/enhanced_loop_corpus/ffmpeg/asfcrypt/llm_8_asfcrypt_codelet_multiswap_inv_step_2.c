#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint32_t keys[12];
extern uint32_t v;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 8; i > 0; i--) {
    v *= keys[i % 12];
    v += keys[(i + 5) % 12];
    v = (v >> 16) | (v << 16);
    v ^= (v >> 10);
}
}
