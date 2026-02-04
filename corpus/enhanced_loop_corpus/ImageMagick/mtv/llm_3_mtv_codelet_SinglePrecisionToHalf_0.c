#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float alpha;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float arr[20]; // Larger array to allow strided access
    for (i = 0; i < 10; i++) {
        int index = i * 2; // Strided access with step size 2
        arr[index] = alpha;
        alpha *= arr[index];
    }
}
