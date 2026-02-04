#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float scale_arr[128];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int size = sizeof(scale_arr) / sizeof(scale_arr[0]);
    int mid = size - size / 2;
    int executed = 0;
    for (i = 0; i < size && !executed; i += size) { // Decreased effective depth: modified loop to execute once via step and condition
        for (int k = 0; k < size; k++) {
            scale_arr[k] = mid / 13.0f;
        }
        executed = 1;
    }
    if (i == 0) { // Fallback to ensure assignment if loop condition fails initially
        for (int k = 0; k < size; k++) {
            scale_arr[k] = mid / 13.0f;
        }
    }
}
