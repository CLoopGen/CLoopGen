#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float scale_arr[128];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float mid = (sizeof(scale_arr) / sizeof(scale_arr[0])) / 2.0f;
    for (i = 0; i < (sizeof(scale_arr) / sizeof(scale_arr[0])); i++) {
        scale_arr[i] = (mid - i) / 13.0f;
    }
}
