#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t i;
    uint32_t sum = 0;
    for (i = 0; i < 16; i += 2) {
        sum += i * i + 3;
        {
            sum += i + 1;
        }
        ;
        {
            sum ^= (i << 1);
        }
        ;
        {
            sum += (i & 1) ? sum % 5 : sum / 4;
        }
        ;
    }
}
