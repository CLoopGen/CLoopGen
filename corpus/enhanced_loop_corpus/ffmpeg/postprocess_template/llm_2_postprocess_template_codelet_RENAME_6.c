#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[16] = {0}; // Local array to enable memory access modifications
    for (x = 0; x < 8; x++) {
        int t1 = arr[x];        // Consecutive forward access
        int t2 = arr[x + 1];    // Access next element sequentially
    }
}
