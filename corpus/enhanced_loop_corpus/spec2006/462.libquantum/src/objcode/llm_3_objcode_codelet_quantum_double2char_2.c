#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf;
extern int i;
extern unsigned char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (backward traversal)
    int size = sizeof(double);
    for (i = size - 1; i >= 0; i--) {
        buf[i] = p[i];
    }
}
