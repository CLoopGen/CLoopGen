#include <stdio.h>

#include <inttypes.h>

extern unsigned char buf1[1024];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i <= 1024; ++i) {
        buf1[i - 1] = ((i % 32) != 0) ? ((i * 2) & 255) : 0;
    }
}
