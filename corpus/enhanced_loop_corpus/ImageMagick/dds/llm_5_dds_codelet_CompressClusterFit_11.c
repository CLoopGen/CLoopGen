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
    for (i = 0; i < (ssize_t)besti && besti >= 0; i++) {
        unordered[o[i]] = (unsigned char)0;
    }
}
