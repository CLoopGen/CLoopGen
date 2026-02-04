#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int d;
extern int e;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_d = d;
    for (e = 0; local_d <= 2048; e++) {
        local_d <<= 1;
    }
    d = local_d;
}
