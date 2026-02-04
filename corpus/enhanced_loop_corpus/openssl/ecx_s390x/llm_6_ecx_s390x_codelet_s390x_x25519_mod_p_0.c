#include <stdio.h>

#include <inttypes.h>

extern unsigned char u_red[32];
extern unsigned int c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int temp = c;
    for (i = 30; i >= 0; i--) {
        temp += (unsigned int)u_red[i];
        u_red[i] = (unsigned char)temp;
        temp >>= 8;
    }
    c = temp;
}
