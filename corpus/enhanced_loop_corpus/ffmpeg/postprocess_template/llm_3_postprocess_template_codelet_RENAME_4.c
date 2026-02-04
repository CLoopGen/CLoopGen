#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[6] = {5, 15, 25, 35, 45, 55};
    for (x = 0; x < 2; x++) {
        // Strided memory access: accessing elements with a stride of 2
        printf("%d ", arr[x * 2]);
    }
}
