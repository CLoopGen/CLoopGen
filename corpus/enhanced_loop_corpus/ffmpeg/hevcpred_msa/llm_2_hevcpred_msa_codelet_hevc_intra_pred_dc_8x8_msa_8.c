#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t col;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t arr[15] = {0};
    for (col = 1; col < 8; col++) {
        arr[col * 2] = col; // Strided access with stride of 2
    }
}
