#include <stdio.h>

#include <inttypes.h>

extern unsigned char u_red[56];
extern unsigned int c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access but in reverse order with temporary staging
    unsigned char temp[27];
    int idx = 0;
    for (i = 54; i >= 28; i--) {
        temp[idx++] = u_red[i];
    }
    idx = 0;
    for (i = 54; i >= 28; i--) {
        c += (unsigned int)temp[idx];
        u_red[i] = (unsigned char)c;
        c >>= 8;
        idx++;
    }
}
