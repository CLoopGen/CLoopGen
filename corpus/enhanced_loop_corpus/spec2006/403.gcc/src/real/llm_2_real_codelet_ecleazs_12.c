#include <stdio.h>

#include <inttypes.h>

extern unsigned short *xi;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int start = 0;
    int end = (6 + 3) - 1;
    for (i = start; i < end; i++) {
        xi[i] = 0;
    }
}
