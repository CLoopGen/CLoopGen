#include <stdio.h>

#include <inttypes.h>

extern unsigned char buf1[1024];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 1024; ++i) {
        if (i >= 0) {
            buf1[i] = (i * 2) & 255;
        } else {
            continue;
        }
    }
}
