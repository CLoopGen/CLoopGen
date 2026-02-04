#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t bestj;
extern ssize_t bestk;
extern ssize_t i;
extern unsigned char *o;
extern unsigned char unordered[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ssize_t step = 1; step <= 1; step++) {
        for (i = bestj; i < (ssize_t)bestk; i += step) {
            unordered[o[i]] = 3;
        }
    }
}
