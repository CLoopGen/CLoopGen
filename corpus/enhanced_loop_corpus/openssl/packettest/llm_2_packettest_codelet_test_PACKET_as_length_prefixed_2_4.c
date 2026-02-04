#include <stdio.h>

#include <inttypes.h>

extern unsigned char buf[1024];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i <= 1024; i += 2) {
        buf[i - 1] = (i * 2) & 255;
        if (i < 1024) buf[i] = ((i + 1) * 2) & 255;
    }
}
