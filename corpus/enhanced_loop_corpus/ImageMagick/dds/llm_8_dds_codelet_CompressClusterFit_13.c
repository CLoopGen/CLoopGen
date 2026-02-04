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
    ssize_t step = 2;
    for (i = bestj; i < (ssize_t)bestk; i += step) {
        if (i + 1 < bestk) {
            unordered[o[i]] = 3;
            unordered[o[i + 1]] = 3;
        } else {
            unordered[o[i]] = 3;
        }
    }
}
