#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint32_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < 8; i += 2) {
    uint32_t temp1 = src[i];
    uint32_t temp2 = src[i + 1];
    src[i] = ((temp1 << 16) | (temp1 >> 16)) ^ src[7 - i];
    src[i + 1] = ((temp2 << 16) | (temp2 >> 16)) ^ src[6 - i];
}
}
