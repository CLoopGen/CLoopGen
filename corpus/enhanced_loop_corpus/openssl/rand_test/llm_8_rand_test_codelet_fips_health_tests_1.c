#include <stdio.h>

#include <inttypes.h>

extern uint8_t buf[1000];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 40; i += 2) {
        uint8_t temp = i + 5;
        buf[i] = (temp > 15) ? 200 : (temp & 255);
    }
}
