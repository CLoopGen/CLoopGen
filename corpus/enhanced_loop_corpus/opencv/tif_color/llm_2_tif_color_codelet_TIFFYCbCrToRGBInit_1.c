#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[512];
    for (i = 0, x = -128; i < 256; i++, x++) {
        arr[i * 2] = x; // Strided access: write to every second element
    }
}
