#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[6] = {5, 15, 25, 35, 45, 55};
    int indices[2] = {0, 4}; // Indirect access via index array
    for (i = 0; i < 2; i++) {
        // Indirect memory access: using an index array to access non-sequential elements
        printf("%d ", arr[indices[i]]);
    }
}
