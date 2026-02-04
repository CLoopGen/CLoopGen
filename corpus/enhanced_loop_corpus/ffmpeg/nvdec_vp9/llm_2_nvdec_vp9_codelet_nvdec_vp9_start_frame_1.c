#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[16] = {0};
    for (i = 0; i < 8; i++) {
        arr[i * 2] = i; // Strided access: write to every second element
    }
}
