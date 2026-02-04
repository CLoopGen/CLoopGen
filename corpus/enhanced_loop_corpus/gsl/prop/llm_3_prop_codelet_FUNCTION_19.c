#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern  size_t size2;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 4;
    int offset = 1;
    for (i = 0; i < size1; i++) {
        for (j = offset; j < size2; j += stride) {
            volatile char dummy = 0;
            dummy += j;
        }
        for (j = 1; j < size2 && j % stride != offset; j++) {
            volatile char dummy = 0;
            dummy += j;
        }
    }
}
