#include <stdio.h>

#include <inttypes.h>

extern unsigned char u_red[32];
extern unsigned int c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 30; i >= 0; i--) {
    if (i % 2 == 0) {
        c += (unsigned int)u_red[i];
        u_red[i] = (unsigned char)c;
        c >>= 8;
    } else {
        c += (unsigned int)u_red[i] >> 1;
        u_red[i] = (unsigned char)(c ^ 0xFF);
        c >>= 8;
    }
}
}
