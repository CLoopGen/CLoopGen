#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned short d[20];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride
    // Access elements with a larger stride, writing to every 4th element starting from offset
    for (i = 0; i < 10; ++i) {
        d[4 * i] = 0;
        d[4 * i + 2] = 0;
    }
}
