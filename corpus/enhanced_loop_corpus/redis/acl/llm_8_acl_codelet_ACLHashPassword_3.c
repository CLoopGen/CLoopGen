#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned char hash[32];
extern char hex[64];
extern char *cset;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int j = 0; j < 32; j++) {
    unsigned char high_nibble = hash[j] >> 4;
    unsigned char low_nibble = hash[j] & 0xF;
    hex[j * 2] = cset[high_nibble];
    hex[j * 2 + 1] = cset[low_nibble];
}
}
