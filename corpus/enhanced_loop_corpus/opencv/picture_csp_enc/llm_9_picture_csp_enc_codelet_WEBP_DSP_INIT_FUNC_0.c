#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (v = 0; v <= 1023; v += 4) {
        v += (v & 1) ? 1 : 3;
    }
}
