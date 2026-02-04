#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *in;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 16; i >= 2; i -= 2) {
        in[i] += in[i - 1];
        in[i - 1] += in[i - 2];
        in[i] += in[i - 2];
    }
}
