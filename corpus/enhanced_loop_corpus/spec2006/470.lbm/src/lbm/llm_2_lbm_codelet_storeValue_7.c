#include <stdio.h>

#include <inttypes.h>

extern  char *vPtr;
extern char buffer[4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive forward access with pointer arithmetic
    char *src = vPtr + sizeof(float) - 1;
    char *dst = buffer;
    for (i = 0; i < sizeof(float); i++) {
        *dst++ = *src--;
    }
}
