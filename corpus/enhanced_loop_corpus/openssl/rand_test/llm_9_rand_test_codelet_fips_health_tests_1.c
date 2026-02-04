#include <stdio.h>

#include <inttypes.h>

extern uint8_t buf[1000];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 10; i++) {
        buf[i * 2] = i * 2 < 10 ? (i * 2) : 200;
        buf[i * 2 + 1] = (i * 2 + 1) < 10 ? (i * 2 + 1) : 200;
    }
}
