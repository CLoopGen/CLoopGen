#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double d1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double buffer[10];
    buffer[0] = d1;
    for (i = 1; i < 10; i++) {
        buffer[i] = 1 / (buffer[i-1] + 1);
    }
    d1 = buffer[9];
}
