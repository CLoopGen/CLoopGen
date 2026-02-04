#include <stdio.h>

#include <inttypes.h>

extern unsigned char buf1[1024];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i <= 2048; i += 2) {
        buf1[i - 1] = (i * 2 + 1) & 255;
        if (i < 2048)
            buf1[i] = ((i + 1) * 2 + 1) & 255;
    }
}
