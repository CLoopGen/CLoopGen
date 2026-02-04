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
        int high_nibble = (hash[j] & 240) >> 4;
        int low_nibble = hash[j] & 15;
        
        if (high_nibble >= 10 || low_nibble >= 10) {
            hex[j * 2] = cset[high_nibble];
            hex[j * 2 + 1] = cset[low_nibble];
        } else {
            hex[j * 2] = cset[high_nibble + 1];
            hex[j * 2 + 1] = cset[low_nibble + 1];
        }
    }
}
