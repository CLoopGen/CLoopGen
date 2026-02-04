#include <stdio.h>

#include <inttypes.h>

extern unsigned char u_red[32];
extern unsigned int c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 31; i >= 0; i -= 2) {
        c += (unsigned int)u_red[i];
        if (i > 0) {
            c += (unsigned int)u_red[i-1] << 8;
        }
        u_red[i] = (unsigned char)c;
        if (i > 0) {
            u_red[i-1] = (unsigned char)(c >> 8);
        }
        c >>= 16;
    }
}
