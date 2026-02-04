#include <stdio.h>

#include <inttypes.h>

extern uint8_t buf[1000];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t prev = 0;
    for (i = 0; i < sizeof(buf); i++) {
        if (i > 0)
            buf[i] = 255 & (prev + ((i >= 512 && i % 8 == 0) ? 128 : i));
        else
            buf[i] = 255 & (i >= 512 && i % 8 == 0 ? 128 : i);
        prev = buf[i];
    }
}
