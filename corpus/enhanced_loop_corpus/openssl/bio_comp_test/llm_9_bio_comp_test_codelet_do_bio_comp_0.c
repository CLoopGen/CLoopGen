#include <stdio.h>

#include <inttypes.h>

extern unsigned char *original;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8 * 1024; i++) {
        int val1 = i & 255;
        int val2 = (i + 1) & 255;
        int val3 = (i + 2) & 255;
        int val4 = (i + 3) & 255;
        original[4*i]     = val1;
        original[4*i + 1] = val2;
        original[4*i + 2] = val3;
        original[4*i + 3] = val4;
    }
}
