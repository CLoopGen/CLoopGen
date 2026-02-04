#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int len;
extern uint16_t count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (len = 0; len <= 3; len++) {
        for (uint16_t i = 0; i <= 3; i++) {
            count[len * 4 + i] = 0;
        }
    }
}
