#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[128];
    for (k = 0; k < 64; k++) {
        arr[k * 2] = k; // Strided access with stride 2
    }
}
