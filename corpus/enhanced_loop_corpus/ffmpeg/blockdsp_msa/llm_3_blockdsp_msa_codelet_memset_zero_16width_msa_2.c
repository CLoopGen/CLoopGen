#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t stride;
extern int32_t height;
extern int8_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with intermediate pointer arithmetic unrolled in steps of 2
    int32_t iterations = height / 2;
    uint8_t *temp_src = src;
    for (int32_t i = 0; i < iterations; ++i) {
        temp_src += stride;
        temp_src += stride;
    }
    src = temp_src;
}
