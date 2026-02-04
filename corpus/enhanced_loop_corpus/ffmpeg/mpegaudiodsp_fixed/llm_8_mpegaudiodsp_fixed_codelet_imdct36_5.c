#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *in;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 17; i >= 5; i -= 3) {
        in[i] += in[i - 2] + in[i - 4] - in[i - 6];
    }
}
