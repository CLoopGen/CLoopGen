#include <stdio.h>

#include <inttypes.h>

extern uint8_t buf[1000];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < sizeof(buf) / 2; i++) {
        size_t forward = i;
        size_t backward = sizeof(buf) - 1 - i;
        buf[forward] = 255 & (forward >= 512 && forward % 8 == 0 ? 128 : (forward ^ 0xAA));
        buf[backward] = 255 & (backward >= 512 && backward % 8 == 0 ? 128 : (backward ^ 0x55));
    }
}
