#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t n;
extern  size_t k;
extern size_t *data;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp;
    for (; i < k; i++) {
        temp = n - k + i;
        data[i] = temp;
    }
}
