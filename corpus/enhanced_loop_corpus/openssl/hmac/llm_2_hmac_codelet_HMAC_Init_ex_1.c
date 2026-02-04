#include <stdio.h>

#include <inttypes.h>

extern int i;
extern unsigned char pad[144];
extern unsigned char keytmp[144];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 3
    int i;
    for (i = 0; i < 144; i += 3) {
        pad[i] = 92 ^ keytmp[i];
        if (i + 1 < 144) pad[i + 1] = 92 ^ keytmp[i + 1];
        if (i + 2 < 144) pad[i + 2] = 92 ^ keytmp[i + 2];
    }
}
