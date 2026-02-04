#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[32] = {0}; // Larger array to allow strided access
    for (x = 0; x < 8; x++) {
        int t1;
        int t2;
        int t3;
        // Strided memory access: access every 4th element
        arr[x * 4] = x * 3;
    }
}
