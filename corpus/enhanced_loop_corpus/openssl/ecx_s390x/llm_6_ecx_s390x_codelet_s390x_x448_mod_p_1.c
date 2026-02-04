#include <stdio.h>

#include <inttypes.h>

extern unsigned char u_red[56];
extern unsigned int c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int temp = 0;
    for (i = 54; i >= 28; i--) {
        temp = (unsigned int)u_red[i] + c;
        u_red[i] = (unsigned char)temp;
        c = temp >> 8;
    }
}
