#include <stdio.h>

#include <inttypes.h>

extern int i;
extern unsigned char p_str[33];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < 33; i++) {
        p_str[i] = 0;
        if (i == 32) break;
    }
}
