#include <stdio.h>

#include <inttypes.h>

extern uint8_t buf[1000];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < sizeof (buf); i += 2) {
        buf[i] = 255 & i;
        if (i + 1 < sizeof (buf)) {
            buf[i + 1] = 255 & (i + 1);
        }
    }
}
