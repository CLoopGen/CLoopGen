#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef int32 tsize_t;

typedef unsigned short uint16;

extern tsize_t stride;
extern uint16 *wp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16 *local_wp = wp;
    tsize_t s = stride;
    for (i = s - 4; i > 0; i -= 2) {
        local_wp[s] += local_wp[0];
        local_wp++;
        if (i > 1) {
            local_wp[s] += local_wp[0];
            local_wp++;
        }
    }
    wp = local_wp - ((s - 4) - i);
}
