#include <stdio.h>

#include <inttypes.h>

extern  char *p;
extern int hi;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (i = 0; p[i] != 0; i += 2) {
        hi = ((hi * 613) + (unsigned int)(p[i]));
        if (p[i + 1] != 0) {
            hi = ((hi * 613) + (unsigned int)(p[i + 1]));
        }
    }
}
