#include <stdio.h>

#include <inttypes.h>

extern unsigned char ivec[16];
extern int n;
extern int rem;
extern int num;
extern unsigned char ovec[33];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    unsigned char temp[16];
    for (i = 0; i < 16; ++i) {
        temp[i] = ovec[i + num] << rem;
    }
    for (i = 0; i < 16; ++i) {
        ivec[i] = temp[i] | ovec[i + num + 1] >> (8 - rem);
    }
}
