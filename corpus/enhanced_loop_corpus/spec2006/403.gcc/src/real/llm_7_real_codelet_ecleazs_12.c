#include <stdio.h>

#include <inttypes.h>

extern unsigned short *xi;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int k;
    volatile unsigned short dummy = 0; // Prevent compiler optimization, enforce WAW dependency
    for (k = 0; k < (6 + 3) - 1; k++) {
        *xi++ = 0;
        dummy = *xi; // Introduce WAR-like anti-dependence via dummy read (volatile to prevent reordering)
    }
}
