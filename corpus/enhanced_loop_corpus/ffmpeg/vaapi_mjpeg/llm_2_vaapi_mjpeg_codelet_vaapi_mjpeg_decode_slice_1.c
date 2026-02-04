#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[4] = {10, 20, 30, 40};
    for (i = 0; i < 2; i++) {
        // Consecutive memory access: accessing adjacent elements in order
        printf("%d ", arr[i]);
    }
}
