#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t col;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t temp = 0;
    for (col = 0; col < 16; col++) {
        temp += col * col;
    }
    col = temp > 0 ? temp % 16 : 0;
}
