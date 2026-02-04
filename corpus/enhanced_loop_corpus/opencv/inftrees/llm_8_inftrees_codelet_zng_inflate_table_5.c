#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int len;
extern uint16_t count[16];
extern uint16_t offs[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (len = 1; len < 14; len += 2) {
        uint16_t temp1 = count[len];
        uint16_t temp2 = (len + 1 < 14) ? count[len + 1] : 0;
        offs[len + 1] = offs[len] + temp1;
        if (len + 2 < 16) {
            offs[len + 2] = offs[len + 1] + temp2;
        }
    }
}
