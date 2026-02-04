#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t indices[] = {0, 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45, 48, 51, 54, 57};
    size_t stride = 5;
    size_t arr[1027];
    for (i = 0; i < 20; i++) {
        size_t idx = indices[i] * stride;
        if (idx < 1027) {
            arr[idx] = idx;
        }
    }
}
