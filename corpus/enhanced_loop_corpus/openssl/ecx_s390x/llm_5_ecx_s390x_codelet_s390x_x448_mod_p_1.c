#include <stdio.h>

#include <inttypes.h>

extern unsigned char u_red[56];
extern unsigned int c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 54; i >= 28; i--) {
        c += (unsigned int)u_red[i];
        u_red[i] = (unsigned char)c;
        c >>= 8;
        if (c == 0) break;
    }
}
