#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t indices[] = {10, 25, 50, 100, 200, 400, 800};
    size_t arr[1027];
    size_t num_accesses = sizeof(indices) / sizeof(indices[0]);
    for (i = 0; i < num_accesses; i++) {
        arr[indices[i]] = indices[i] * 2;
    }
}
