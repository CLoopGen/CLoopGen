#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; i < (length >> 2); ++i) {
        temp += i * 2;
        temp ^= (temp >> 4);
    }
    // Introduces WAW and RAW dependencies on 'temp' within the loop.
    // Loop-carried dependency via 'temp' creates a sequential execution constraint.
}
