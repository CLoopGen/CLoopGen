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
    ssize_t temp_i = besti;
    while (temp_i < bestj) {
        unordered[o[temp_i]] = 2;
        temp_i++;
    }
}
