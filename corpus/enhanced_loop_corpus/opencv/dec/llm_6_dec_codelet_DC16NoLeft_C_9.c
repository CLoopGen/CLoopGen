#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; i < 16; ++i) {
        temp += i * 2;
    }
    // Introduces a WAW dependency on 'temp' and a loop-carried RAW dependency via temp's accumulation.
    // Original loop had no data dependencies; now there is intra-loop data flow.
}
