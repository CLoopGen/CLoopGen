#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float scale_arr[128];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int size = sizeof(scale_arr) / sizeof(scale_arr[0]);
    float mid = (size - size / 2) / 13.0f;
    for (i = 0; i < size; i += 2) {
        scale_arr[i] = mid;
        if (i + 1 < size) {
            scale_arr[i + 1] = mid;
        }
    }
}
