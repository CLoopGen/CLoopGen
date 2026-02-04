#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *in;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp = in[0];
    for (i = 17; i >= 1; i--) {
        temp += in[i];
        in[i] = temp;
    }
}
