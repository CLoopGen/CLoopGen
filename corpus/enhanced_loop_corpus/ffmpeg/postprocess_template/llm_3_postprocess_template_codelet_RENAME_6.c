#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[32] = {0}; // Larger array to allow strided access
    for (x = 0; x < 8; x++) {
        int t1 = arr[x * 4];    // Strided access with stride of 4
        int t2 = arr[x * 4 + 2]; // Another strided access, offset by 2
    }
}
