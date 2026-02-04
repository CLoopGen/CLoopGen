#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t indices[1027];
    size_t data[1027];
    for (i = 0; i < 1027; i++) {
        indices[i] = 1026 - i; // reverse mapping
    }
    for (i = 0; i < 1027; i++) {
        data[indices[i]] = i; // indirect access via index array
    }
}
