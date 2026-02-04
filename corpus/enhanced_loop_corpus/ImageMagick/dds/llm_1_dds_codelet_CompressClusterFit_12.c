#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t besti;
extern ssize_t bestj;
extern ssize_t i;
extern unsigned char *o;
extern unsigned char unordered[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (besti < bestj) {
        i = besti;
        for (ssize_t nested_iter = 0; nested_iter < (bestj - besti); nested_iter++) {
            unordered[o[i]] = 2;
            i++;
        }
    }
}
