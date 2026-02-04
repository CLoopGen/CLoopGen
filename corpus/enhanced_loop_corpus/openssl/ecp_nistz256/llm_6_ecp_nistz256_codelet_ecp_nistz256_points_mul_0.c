#include <stdio.h>

#include <inttypes.h>

extern int i;
extern unsigned char p_str[33];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char temp = 0;
    for (; i < 33; i++) {
        temp = p_str[i] + temp; // Introduce loop-carried RAW dependency via 'temp'
        p_str[i] = 0;
    }
}
