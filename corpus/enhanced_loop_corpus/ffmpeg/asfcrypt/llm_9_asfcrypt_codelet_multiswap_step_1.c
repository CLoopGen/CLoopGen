#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint32_t keys[12];
extern uint32_t v;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < 3; i += 1) {
    uint32_t temp1 = (v >> 16) | (v << 16);
    uint32_t temp2 = temp1 * keys[i];
    v = (temp2 >> 5) ^ (temp2 + keys[(i+2) % 12]) ^ (temp2 << 7);
}
}
