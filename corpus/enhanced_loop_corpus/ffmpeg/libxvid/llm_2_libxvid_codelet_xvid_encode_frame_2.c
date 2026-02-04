#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[8] = {10, 20, 30, 40, 50, 60, 70, 80};
    for (i = 0; i < 4; i++) {
        // Consecutive memory access: accessing adjacent elements sequentially
        int val = arr[i];
        arr[i] = val + 1;
    }
}
