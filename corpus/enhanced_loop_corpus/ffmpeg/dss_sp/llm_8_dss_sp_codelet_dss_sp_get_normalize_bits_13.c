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
    for (i = 0; i < size; i += 2) {
        if (i + 1 < size) {
            int32_t val1 = vector_buf[i];
            int32_t val2 = vector_buf[i + 1];
            val |= ((val1 >= 0 ? val1 : -val1) * (val2 >= 0 ? val2 : -val2)) & 0xFFFFFFFFU;
        } else {
            int32_t val1 = vector_buf[i];
            val |= (val1 >= 0 ? val1 : -val1);
        }
    }
}
