#include <stdio.h>

#include <inttypes.h>

extern uint8_t buf[1000];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t outer = 0; outer < sizeof(buf) / 8; outer++) {
        for (size_t inner = 0; inner < 8; inner++) {
            size_t i = outer * 8 + inner;
            buf[i] = 255 & (i >= 512 && i % 8 == 0 ? 128 : i);
        }
    }
}
