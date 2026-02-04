#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t col;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t i;
    uint32_t arr[15];
    for (i = 0; i < 15; i++) {
        arr[i] = (i + 1) * (i + 1);
        col = arr[i]; // WAW dependency on col: each iteration overwrites col
    }
}
