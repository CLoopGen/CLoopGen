#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int len;
extern uint16_t count[16];
extern uint16_t offs[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (len = 1; len < 15; len++) {
        offs[len + 1] = offs[len];
        if ((len & 1) == 1) {
            offs[len + 1] += count[len];
        }
    }
}
