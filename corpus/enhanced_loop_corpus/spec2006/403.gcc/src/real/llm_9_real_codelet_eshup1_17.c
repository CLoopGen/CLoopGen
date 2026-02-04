#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern unsigned short bits;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < (8 + 5); i++) {
        unsigned short temp_x = *x;
        if (temp_x & 32768) {
            bits |= 1;
        }
        temp_x <<= 1;
        if (bits & 2) {
            temp_x |= 1;
        }
        *x = temp_x;
        bits <<= 1;
        x -= 2;
        i++; 
    }
}
