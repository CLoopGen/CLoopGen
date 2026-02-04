#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[8];
    for (i = 0; i < 8; i++) {
        arr[i] = i; // Write to array element (WAW dependency across iterations if unrolled)
    }
    for (i = 1; i < 8; i++) {
        arr[i] += arr[i-1]; // Introduces RAW loop-carried dependency: each iteration depends on previous
    }
}
