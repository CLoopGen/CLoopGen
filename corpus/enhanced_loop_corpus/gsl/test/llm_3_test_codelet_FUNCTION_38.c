#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t indices[] = {0, 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45, 48, 51, 54, 57};
    size_t arr[1027] = {0};
    size_t len = sizeof(indices) / sizeof(indices[0]);
    for (i = 0; i < len; i++) {
        arr[indices[i]] = indices[i] * 2;
    }
}
