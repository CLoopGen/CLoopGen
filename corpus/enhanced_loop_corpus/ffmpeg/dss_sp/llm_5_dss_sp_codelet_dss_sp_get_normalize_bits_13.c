#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *vector_buf;
extern int16_t size;
extern unsigned int val;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    val = 0;
    for (i = 0; i < size; i++) {
        int32_t abs_val = vector_buf[i];
        if (abs_val < 0) {
            abs_val = -abs_val;
        }
        val |= abs_val;
    }
}
