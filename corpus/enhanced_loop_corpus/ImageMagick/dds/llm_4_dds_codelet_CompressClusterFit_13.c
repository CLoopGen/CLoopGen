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
    if (bestj >= bestk) return;
    for (i = bestj; i < (ssize_t)bestk; i++) {
        unordered[o[i]] = 3;
    }
}
