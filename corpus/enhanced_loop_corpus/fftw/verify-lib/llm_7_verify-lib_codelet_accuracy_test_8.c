#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double t[6];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 5; i >= 0; --i)
        t[i] = 0.;  // Reverse loop direction to eliminate potential forward loop-carried dependencies; no inter-iteration dependency
}
