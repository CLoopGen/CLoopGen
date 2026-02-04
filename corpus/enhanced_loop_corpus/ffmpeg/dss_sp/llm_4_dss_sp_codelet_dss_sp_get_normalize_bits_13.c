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
    for (i = 0; i < size; i++) {
        int32_t element = vector_buf[i];
        if (element == 0) continue;
        val |= (element > 0) ? element : -element;
    }
}
