#include <stdio.h>

#include <inttypes.h>

extern int i;
extern unsigned char pad[144];
extern unsigned char keytmp[144];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access pattern
    int i;
    for (i = 143; i >= 0; i--)
        pad[i] = 54 ^ keytmp[i];
}
