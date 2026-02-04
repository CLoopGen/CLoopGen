#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t count;
extern ssize_t bestk;
extern ssize_t i;
extern unsigned char *o;
extern unsigned char unordered[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (bestk < (ssize_t)count) {
        for (i = bestk; i < (ssize_t)count; i += 2) {
            unordered[o[i]] = 1;
            if (i + 1 < (ssize_t)count)
                unordered[o[i + 1]] = 1;
        }
    }
}
