#include <stdio.h>

#include <inttypes.h>

extern unsigned char *original;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16 * 1024; i++) {
        original[i] = i & 255;
        original[i + 16*1024] = (i + 16*1024) & 255;
    }
}
