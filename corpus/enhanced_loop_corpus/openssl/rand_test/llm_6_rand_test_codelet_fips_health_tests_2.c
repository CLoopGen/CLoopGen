#include <stdio.h>

#include <inttypes.h>

extern uint8_t buf[1000];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    uint8_t temp;
    for (i = 0; i < sizeof(buf); i++) {
        temp = (i >= 512 && i % 8 == 0) ? 128 : i;
        buf[i] = 255 & temp;
    }
}
