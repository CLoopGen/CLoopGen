#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned char s[256];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < 256; k++) {
        s[k] = k;
        if (k > 0) {
            s[k] += s[k-1]; // Introduces RAW dependency: current iteration reads previous write
        }
    }
}
