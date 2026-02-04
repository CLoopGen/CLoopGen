#include <stdio.h>

#include <inttypes.h>

extern uint8_t buf[1000];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < sizeof(buf); i++) {
        if (i < 512) {
            buf[i] = 255 & i;
            continue;
        }
        if (i % 8 == 0) {
            buf[i] = 128;
        } else {
            buf[i] = 255 & i;
        }
    }
}
