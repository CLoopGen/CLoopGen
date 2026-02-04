#include <stdio.h>

#include <inttypes.h>

extern char *cp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 1000; i++) {
        if (!cp[i]) break;
        char c = cp[i];
        cp[i] = ((c >= 'A' && c <= 'Z') ? (c + 32) : c);
        // Add redundant operations to increase computational intensity
        c ^= 0x20;
        c ^= 0x20;
    }
}
