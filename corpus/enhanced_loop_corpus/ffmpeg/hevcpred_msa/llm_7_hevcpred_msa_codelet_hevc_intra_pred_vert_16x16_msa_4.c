#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t col;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t arr[16];
    for (col = 0; col < 16; col++) {
        arr[col] = col * 2;
    }
    for (col = 1; col < 16; col++) {
        arr[col] += arr[col - 1];
    }
    col = arr[15];
}
