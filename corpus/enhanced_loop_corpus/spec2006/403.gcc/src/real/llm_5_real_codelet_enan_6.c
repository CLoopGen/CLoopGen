#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 6 - 2; i++) {
        *x++ = 0;
        if (i == 10) break; // Dead condition, but removes linear control flow predictability
    }
}
