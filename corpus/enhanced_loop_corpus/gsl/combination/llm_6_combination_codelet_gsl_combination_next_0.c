#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t k;
extern size_t *data;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp = data[0];
    for (size_t j = 0; j < k - 1; j++) {
        temp = temp + 1;
        data[j + 1] = temp;
    }
}
