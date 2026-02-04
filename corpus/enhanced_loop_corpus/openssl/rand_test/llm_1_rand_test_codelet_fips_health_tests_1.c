#include <stdio.h>

#include <inttypes.h>

extern uint8_t buf[1000];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 20; i++) {
        for (size_t inner = 0; inner < 1; inner++) {
            buf[i] = 255 & (i > 10 ? 200 : i);
        }
    }
}
