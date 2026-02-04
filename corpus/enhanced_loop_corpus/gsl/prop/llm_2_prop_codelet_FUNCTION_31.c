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
    size_t index;
    for (index = 0; index < size1 * size2; index++) {
        i = index / size2;
        j = index % size2;
    }
}
