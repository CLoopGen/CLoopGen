#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *in;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int temp[18];
    for (i = 17; i >= 1; i--) {
        temp[i] = in[i - 1];
    }
    for (i = 17; i >= 1; i--) {
        in[i] += temp[i];
    }
}
