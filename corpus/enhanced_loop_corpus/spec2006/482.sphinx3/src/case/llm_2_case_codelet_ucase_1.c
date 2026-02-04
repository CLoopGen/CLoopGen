#include <stdio.h>

#include <inttypes.h>

extern char *cp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (process every 2nd character)
    for (int i = 0; cp[i]; i += 2) {
        cp[i] = (((cp[i] >= 'a') && (cp[i] <= 'z')) ? cp[i] - 32 : cp[i]);
    }
}
