#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t col;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (col = 0; col < 16 && col != 10; col++) {
        if (col % 3 == 0) {
            col += 2;
        }
    }
}
