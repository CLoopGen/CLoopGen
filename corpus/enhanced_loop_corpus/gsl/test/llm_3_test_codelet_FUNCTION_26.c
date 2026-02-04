#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t indices[1027];
    for (i = 0; i < 1027; i++) {
        indices[i] = (i * 7) % 1027; // Generate strided indirect indices
    }
    size_t arr[1027];
    for (i = 0; i < 1027; i++) {
        size_t idx = indices[i];
        arr[idx] = idx;
    }
}
