#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[6] = {5, 15, 25, 35, 45, 55};
    for (i = 0; i < 2; i++) {
        // Strided memory access: accessing elements with a stride of 2
        printf("%d ", arr[i * 2]);
    }
}
