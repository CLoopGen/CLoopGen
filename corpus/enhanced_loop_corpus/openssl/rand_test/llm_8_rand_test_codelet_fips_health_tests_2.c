#include <stdio.h>

#include <inttypes.h>

extern uint8_t buf[1000];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < sizeof(buf); i += 2) {
        uint8_t val = (i >= 512 && (i % 16 == 0)) ? 128 : (i * 3 + 7) % 255;
        buf[i] = val;
        if (i + 1 < sizeof(buf)) {
            buf[i + 1] = 255 & ((i + 1) >= 512 && ((i + 1) % 8 == 0) ? 128 : (i + 1));
        }
    }
}
