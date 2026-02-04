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
        int idx = j * 2;
        unsigned char val = hash[j];
        hex[idx] = cset[(val >> 4) & 15];
        hex[idx + 1] = cset[val & 15];
    }
}
