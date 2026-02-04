#include <stdio.h>

#include <inttypes.h>

extern int i;
extern unsigned char pad[144];
extern unsigned char keytmp[144];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 144; i += 2) {
    pad[i] = 54 ^ keytmp[i];
    if (i + 1 < 144)
        pad[i+1] = 54 ^ keytmp[i+1];
}
}
