#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t a;
extern uint64_t b;
extern uint64_t r;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t local_a[4];
    uint64_t local_r[4];
    local_a[0] = a;
    local_r[0] = r;
    for (i = 0; i < 4; i++) {
        if (i > 0) {
            local_a[i] = local_a[i-1] % b;
            local_a[i] <<= 16;
            local_r[i] = (local_r[i-1] << 16) | (local_a[i] / b);
        } else {
            local_a[i] <<= 16;
            local_r[i] = (r << 16) | (local_a[i] / b);
        }
    }
    a = local_a[3] % b;
    r = local_r[3];
}
