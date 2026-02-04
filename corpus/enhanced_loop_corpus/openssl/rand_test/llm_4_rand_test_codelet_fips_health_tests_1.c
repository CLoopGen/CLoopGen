#include <stdio.h>

#include <inttypes.h>

extern uint8_t buf[1000];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 20; i++) {
        if (i <= 10) {
            buf[i] = i;
        } else {
            buf[i] = 200;
        }
    }
}
