#include <stdio.h>

#include <inttypes.h>

extern unsigned char u_red[32];
extern unsigned int c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 15; i >= 0; i--) {
        c += (unsigned int)u_red[2*i];
        c += (unsigned int)u_red[2*i+1] << 8;
        u_red[2*i] = (unsigned char)c;
        u_red[2*i+1] = (unsigned char)(c >> 8);
        c >>= 16;
    }
}
