#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float INTFLOAT;

extern INTFLOAT *buf;
extern int i;
extern  int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with larger stride (access every 4th element, but process two at a time)
    for (i = 0; i < n; i += 4) {
        if (i + 0 < n) buf[i + 0] = -buf[i + 0];
        if (i + 2 < n) buf[i + 2] = -buf[i + 2];
    }
}
