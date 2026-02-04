#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int d;
extern int e;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = d;
    for (e = 0; d <= 2048; e++) {
        temp <<= 1;
        d = temp;
    }
}
