#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[8] = {10, 20, 30, 40, 50, 60, 70, 80};
    for (i = 0; i <= 3; ++i) {
        // Strided memory access: accessing every second element starting from index 0
        printf("%d ", arr[i * 2]);
    }
}
