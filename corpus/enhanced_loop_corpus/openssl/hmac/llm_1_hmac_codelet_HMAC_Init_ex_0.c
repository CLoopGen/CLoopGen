#include <stdio.h>

#include <inttypes.h>

extern int i;
extern unsigned char pad[144];
extern unsigned char keytmp[144];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i;
for (i = 0; i < 72; i++) {
    pad[i] = 54 ^ keytmp[i];
    pad[i + 72] = 54 ^ keytmp[i + 72];
}
}
