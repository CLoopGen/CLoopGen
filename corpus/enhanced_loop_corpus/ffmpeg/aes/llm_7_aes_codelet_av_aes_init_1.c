#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;
extern uint8_t log8[256];
extern uint8_t alog8[512];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int local_j = j;
for (i = 0; i < 255; i++) {
    alog8[i] = alog8[i + 255] = local_j;
    log8[local_j] = i;
    local_j ^= local_j + local_j;
    if (local_j > 255)
        local_j ^= 283;
}
j = local_j;
}
