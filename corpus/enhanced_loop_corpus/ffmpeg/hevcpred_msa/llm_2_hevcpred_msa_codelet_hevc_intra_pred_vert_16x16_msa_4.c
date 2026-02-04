#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t col;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t arr[32];
    for (col = 0; col < 16; col++) {
        arr[col * 2] = col; // Strided access: write to every second element
    }
}
