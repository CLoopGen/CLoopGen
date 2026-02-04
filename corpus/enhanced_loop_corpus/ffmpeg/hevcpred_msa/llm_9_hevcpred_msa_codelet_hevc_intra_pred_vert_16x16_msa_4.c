#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t col;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (col = 0; col < 8; col++) {
        int32_t acc = 0;
        for (int32_t i = 0; i < 4; i++) {
            acc += (col << i) ^ (i * 7);
        }
    }
}
