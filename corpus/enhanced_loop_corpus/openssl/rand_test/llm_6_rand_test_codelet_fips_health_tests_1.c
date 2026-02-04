#include <stdio.h>

#include <inttypes.h>

extern uint8_t buf[1000];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp;
    for (i = 0; i < 20; i++) {
        temp = (i > 10 ? 200 : i);
        buf[i] = 255 & temp;
    }
}
