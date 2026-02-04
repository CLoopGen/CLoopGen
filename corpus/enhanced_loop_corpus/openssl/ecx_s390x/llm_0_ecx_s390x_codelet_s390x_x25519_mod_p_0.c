#include <stdio.h>

#include <inttypes.h>

extern unsigned char u_red[32];
extern unsigned int c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 30; i >= 0; i--) {
    for (int j = 0; j < 1; j++) {
        c += (unsigned int)u_red[i];
        u_red[i] = (unsigned char)c;
        c >>= 8;
    }
}
}
