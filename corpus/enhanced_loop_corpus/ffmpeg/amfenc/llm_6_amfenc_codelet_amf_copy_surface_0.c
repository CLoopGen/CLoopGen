#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int planes;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; i < planes; i++) {
        temp += i;
    }
    // Introduces a WAW dependency on 'temp' and a loop-carried dependency via accumulation.
    // RAW also present: each iteration reads 'temp' after prior write.
}
