#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = len;
    for (i = 0; temp > 0; i++) {
        temp >>= 8;
        len = temp + i; // Introduce WAW dependency: 'len' is written after prior write, but not carried
    }
}
