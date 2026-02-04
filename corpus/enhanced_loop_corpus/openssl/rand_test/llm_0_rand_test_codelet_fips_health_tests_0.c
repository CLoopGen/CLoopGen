#include <stdio.h>

#include <inttypes.h>

extern uint8_t buf[1000];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t outer = 0; outer < sizeof(buf) / 10; outer++) {
        for (size_t inner = 0; inner < 10; inner++) {
            size_t i = outer * 10 + inner;
            buf[i] = 255 & i;
        }
    }
}
