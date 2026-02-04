#include <stdio.h>

#include <inttypes.h>

extern  char *p;
extern int hi;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (i = 0; p[i] != 0 && i < 1000; i++) {
        hi = ((hi * 613) + (unsigned int)(p[i]));
        hi = ((hi * 37) + (unsigned int)(p[i] ^ 0x55));
        hi = ((hi + 917) ^ (unsigned int)(p[i] << 2));
    }
}
