#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float scale_arr[128];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int size = sizeof(scale_arr) / sizeof(scale_arr[0]);
    for (i = 0; i < size; i++) {
        for (int j = 0; j < 1; j++) { // Increased loop depth: introduced a nested loop with fixed iteration
            scale_arr[i] = (size - size / 2) / 13.0f;
        }
    }
}
