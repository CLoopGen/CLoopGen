#include <stdio.h>

#include <inttypes.h>

extern unsigned long accum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    unsigned long temp = accum;
    for (i = 0; temp != 0; ++i) {
        temp = temp >> 1;
    }
    accum = temp;
}
