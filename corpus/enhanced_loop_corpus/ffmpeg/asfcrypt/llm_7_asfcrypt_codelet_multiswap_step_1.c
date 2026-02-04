#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint32_t keys[12];
extern uint32_t v;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_v[4];
    local_v[0] = v;
    for (i = 1; i < 5; i++) {
        local_v[i-1] = (local_v[i-1] >> 16) | (local_v[i-1] << 16);
        local_v[i-1] *= keys[i];
    }
    v = local_v[3];
}
