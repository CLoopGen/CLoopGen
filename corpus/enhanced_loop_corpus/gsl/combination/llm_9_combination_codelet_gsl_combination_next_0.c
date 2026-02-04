#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t k;
extern size_t *data;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < k * 2; i++) {
        data[i % k] = data[(i + 1) % k] + 2;
        data[(i + 1) % k] = data[i % k] + 3;
    }
}
