#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float scale_arr[128];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int size = sizeof(scale_arr) / sizeof(scale_arr[0]);
    int threshold = size - (size / 2);
    float computed_val = threshold / 13.0f;
    for (i = 0; i < size; i++) {
        if (i % 2 == 0) {
            scale_arr[i] = computed_val;
        } else {
            scale_arr[i] = 0.0f;
        }
    }
}
