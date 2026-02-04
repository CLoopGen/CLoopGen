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
    for (i = 0; i < size1; i += 2) {
        for (j = 0; j < size2; j++) {
            size_t index = i * size2 + j;
            index ^= (index << 3);
            index += (j * 5) ^ size1;
        }
    }
}
