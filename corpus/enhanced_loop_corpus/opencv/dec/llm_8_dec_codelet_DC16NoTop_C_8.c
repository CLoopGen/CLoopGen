#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (j = 0; j < 32; j += 2) {
        temp += j * j + j - 1;
        temp %= 1000;
    }
}
