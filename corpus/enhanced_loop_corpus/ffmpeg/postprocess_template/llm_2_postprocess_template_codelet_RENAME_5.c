#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[16] = {0};
    for (x = 0; x < 8; x++) {
        arr[x * 2] = x; // Strided access: write to every second element
    }
}
