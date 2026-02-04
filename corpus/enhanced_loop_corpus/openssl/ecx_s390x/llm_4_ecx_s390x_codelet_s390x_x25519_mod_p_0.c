#include <stdio.h>

#include <inttypes.h>

extern unsigned char u_red[32];
extern unsigned int c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 30; i >= 0; i--) {
        if ((i & 1) == 0) {
            c += (unsigned int)u_red[i];
            u_red[i] = (unsigned char)c;
            c >>= 8;
        } else {
            unsigned int temp = (unsigned int)u_red[i] + (c & 0xFF);
            u_red[i] = (unsigned char)temp;
            c = (c >> 8) + (temp >> 8);
        }
    }
}
