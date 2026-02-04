#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[32];
    for (i = 0; i < 16; i++) {
        arr[i * 2] = i; // Strided access: write to every second element
    }
}
