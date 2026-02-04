#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[60];
    for (; idx < 15; idx += 4) {
        register unsigned int v, g = v & 16711935;
        v &= 4278255360U;
        arr[idx * 4] = 1;          // Strided access with stride 4
        arr[idx * 4 + 1] = 2;
        arr[idx * 4 + 2] = 3;
        arr[idx * 4 + 3] = 4;
    }
}
