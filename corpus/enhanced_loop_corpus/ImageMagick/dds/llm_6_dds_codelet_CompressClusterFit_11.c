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
    ssize_t temp[16] = {0};
    for (i = 0; i < (ssize_t)besti; i++) {
        ssize_t index = o[i];
        temp[index] = 1;
    }
    for (i = 0; i < 16; i++) {
        if (temp[i]) {
            unordered[i] = 0;
        }
    }
}
