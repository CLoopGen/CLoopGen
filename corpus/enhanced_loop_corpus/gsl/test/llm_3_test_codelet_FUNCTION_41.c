#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t indices[] = {0, 3, 6, 9, 12, 15, 18, 21, 24, 27}; // Example small set of indices
    size_t arr[32] = {0};
    size_t len = sizeof(indices) / sizeof(indices[0]);
    for (i = 0; i < 1027; i++) {
        size_t idx = indices[(i % len)];
        arr[idx] += 1;
    }
}
