#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int len;
extern uint16_t count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t temp[16];
    for (len = 0; len <= 15; len++) {
        temp[len] = 0;
        count[len] = temp[len];
    }
}
