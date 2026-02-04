#include <stdio.h>

#include <inttypes.h>

extern uint8_t buf[1000];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp = 0;
    for (i = 0; i < sizeof (buf); i++) {
        temp = 255 & i;
        buf[i] = temp;
    }
}
