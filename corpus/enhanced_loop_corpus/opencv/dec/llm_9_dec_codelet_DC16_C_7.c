#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 8; ++j) {
        int temp = j * j;
        temp += j * 5;
        temp = (temp >> 1) + (temp & 1);
    }
}
