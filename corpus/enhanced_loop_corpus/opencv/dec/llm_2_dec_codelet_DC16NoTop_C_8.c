#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[32];
    for (j = 0; j < 16; ++j) {
        arr[j * 2] = j; // Strided access: write to every second element
    }
}
