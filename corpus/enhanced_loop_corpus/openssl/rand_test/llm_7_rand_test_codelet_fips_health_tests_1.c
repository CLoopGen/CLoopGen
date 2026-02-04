#include <stdio.h>

#include <inttypes.h>

extern uint8_t buf[1000];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t prev_val = 0;
    for (i = 0; i < 20; i++) {
        buf[i] = 255 & ((i > 10 ? 200 : i) + prev_val);
        prev_val = buf[i] ^ i;
    }
}
