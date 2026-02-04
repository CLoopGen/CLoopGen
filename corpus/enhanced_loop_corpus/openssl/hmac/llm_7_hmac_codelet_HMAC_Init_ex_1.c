#include <stdio.h>

#include <inttypes.h>

extern int i;
extern unsigned char pad[144];
extern unsigned char keytmp[144];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char temp[144];
    for (i = 0; i < 144; i++) {
        temp[i] = 92 ^ keytmp[i];
    }
    for (i = 0; i < 144; i++) {
        pad[i] = temp[i];
    }
}
