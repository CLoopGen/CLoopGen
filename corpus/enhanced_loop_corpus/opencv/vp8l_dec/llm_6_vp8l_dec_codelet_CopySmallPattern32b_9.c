#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; i < (length >> 1); ++i) {
        temp += i * 2;
    }
    // Introduces WAW dependency on 'temp' and RAW on 'i'
    // Loop-carried dependency via accumulation in 'temp'
}
