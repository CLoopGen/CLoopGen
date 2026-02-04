#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef unsigned int uint32;

extern int32 n_el;
extern int32 i;
extern uint32 *buf32;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 temp;
    for (i = 0; i < n_el; i++) {
        temp = *(buf32 + i);
        *(buf32 + i) = ((255 & temp >> 24) | (65280 & temp >> 8) | (16711680 & temp << 8) | (4278190080U & temp << 24));
    }
}
