#include <stdio.h>

#include <inttypes.h>

extern unsigned char u_red[56];
extern unsigned int c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 52; i >= 0; i--) {
        c += (unsigned int)u_red[i % 27];
        u_red[i % 27] ^= (unsigned char)(c & 0xFF);
        c += (unsigned int)(u_red[i % 27]) << 1;
        c >>= 8;
    }
}
