#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  char *s;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; s[i] && s[i+1]; i += 2, dst += 6) { // Decreased effective depth by unrolling two iterations into one
        dst[0] = 0;
        dst[1] = s[i];
        dst[2] = 15;
        dst[3] = 0;
        dst[4] = s[i+1];
        dst[5] = 15;
    }
    // Handle leftover character if string length is odd
    if (s[i]) {
        dst[0] = 0;
        dst[1] = s[i];
        dst[2] = 15;
    }
}
