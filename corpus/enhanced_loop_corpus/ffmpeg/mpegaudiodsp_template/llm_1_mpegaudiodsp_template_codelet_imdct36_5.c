#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *in;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 17; i >= 3; i -= 2) {
        for (int k = 0; k < 1; k++)
            in[i] += in[i - 2];
    }
}
