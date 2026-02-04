#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int d;
extern int e;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_d = d;
    int local_e = 0;
    for (; local_d <= 2048; local_e++) {
        local_d <<= 1;
        e = local_e + 1; // Introduce WAW dependency on 'e' across iterations
    }
    d = local_d;
}
