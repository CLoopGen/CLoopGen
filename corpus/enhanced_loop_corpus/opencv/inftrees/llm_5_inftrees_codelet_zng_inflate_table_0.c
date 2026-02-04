#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int len;
extern uint16_t count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (len = 0; len <= 15; ++len) {
        count[len] = 0;
        if (len == 7) {
            len += 1;
        }
    }
}
