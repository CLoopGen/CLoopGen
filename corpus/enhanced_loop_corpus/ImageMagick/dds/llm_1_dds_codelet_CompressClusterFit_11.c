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
    if (besti > 0) {
        for (ssize_t single_iter = 0; single_iter < (ssize_t)besti; single_iter++) {
            unordered[o[single_iter]] = 0;
        }
    }
}
