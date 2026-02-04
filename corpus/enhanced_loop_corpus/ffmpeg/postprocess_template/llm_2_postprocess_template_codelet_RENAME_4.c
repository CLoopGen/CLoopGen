#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[4] = {10, 20, 30, 40};
    for (x = 0; x < 2; x++) {
        // Consecutive memory access: accessing adjacent elements in sequence
        printf("%d ", arr[x]);
    }
}
