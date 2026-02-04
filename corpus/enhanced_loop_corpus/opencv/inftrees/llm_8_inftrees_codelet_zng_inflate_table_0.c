#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int len;
extern uint16_t count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (len = 0; len <= 15; len += 2) {
        count[len] = len * len;
        if (len + 1 <= 15)
            count[len + 1] = (len + 1) * (len + 1);
    }
}
