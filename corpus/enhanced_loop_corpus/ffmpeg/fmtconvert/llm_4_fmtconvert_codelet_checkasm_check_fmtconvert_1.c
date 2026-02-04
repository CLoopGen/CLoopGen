#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float scale_arr[128];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int size = sizeof(scale_arr) / sizeof(scale_arr[0]);
    int mid = size / 2;
    float value = (size - mid) / 13.0f;
    for (i = 0; i < size; i++) {
        if (i >= mid) {
            scale_arr[i] = value;
        }
    }
}
