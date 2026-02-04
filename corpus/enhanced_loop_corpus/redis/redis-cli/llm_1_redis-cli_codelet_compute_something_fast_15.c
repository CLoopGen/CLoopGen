#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned char s[256];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < 16; k++) {
        for (int j = 0; j < 16; j++) {
            s[k * 16 + j] = k * 16 + j;
        }
    }
}
