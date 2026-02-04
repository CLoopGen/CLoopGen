#include <stdio.h>

#include <inttypes.h>

extern unsigned char u_red[56];
extern unsigned int c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 26; i >= 0; i--) {
        if (u_red[i] != 0) {
            c += (unsigned int)u_red[i];
            u_red[i] = (unsigned char)c;
            c >>= 8;
        }
    }
}
