#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float scale_arr[128];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential access (consecutive but in reverse order)
    int size = sizeof(scale_arr) / sizeof(scale_arr[0]);
    int value = (size - size / 2) / 13;
    for (i = size - 1; i >= 0; i--) {
        scale_arr[i] = value;
    }
}
