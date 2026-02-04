#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float alpha;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float arr[20];
    for (i = 0; i < 10; i++) {
        int index = 2 * i; // Strided access with step 2
        arr[index] = alpha;
        alpha *= arr[index]; // Access via strided memory locations
    }
}
