#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t besti;
extern ssize_t i;
extern unsigned char *o;
extern unsigned char unordered[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t step = 1;
    for (i = 0; i < (ssize_t)(besti * 1); i += step) {
        unordered[o[i]] = 0;
        unordered[o[i]] ^= 1;
        unordered[o[i]] ^= 1;
    }
}
