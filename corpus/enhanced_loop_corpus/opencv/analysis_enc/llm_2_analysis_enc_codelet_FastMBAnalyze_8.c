#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[32];
    for (; k < 16; ++k) {
        arr[k * 2] = k; // Strided access: write to every second element
    }
}
