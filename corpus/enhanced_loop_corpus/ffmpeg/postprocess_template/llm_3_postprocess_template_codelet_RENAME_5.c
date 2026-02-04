#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[8] = {0};
    int indices[] = {7, 6, 5, 4, 3, 2, 1, 0};
    for (x = 0; x < 8; x++) {
        arr[indices[x]] = x; // Indirect access via index array (reverse order)
    }
}
