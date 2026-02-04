#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int j;
extern int k;
extern int *offt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 256; i++) {
        int j = i >> 6;          // equivalent to i / 64
        int k = i & 63;          // equivalent to i % 64
        offt[i] = ((k >> 3) << 5) + ((j & 3) << 3) + (k & 7);
    }
}
