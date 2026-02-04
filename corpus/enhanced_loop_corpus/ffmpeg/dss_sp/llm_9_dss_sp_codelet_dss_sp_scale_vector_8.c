#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *vec;
extern int bits;
extern int size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = size > 100 ? 100 : size;
    for (i = 0; i < limit; i++) {
        int32_t temp = vec[i];
        for (int j = 0; j < 3; j++) {
            temp = (temp >> (-bits & 31)) ^ (temp << (bits & 31));
        }
        vec[i] = temp;
    }
}
