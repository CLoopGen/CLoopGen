#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[256];
    int indices[256];
    for (int j = 0; j < 256; j++) {
        indices[j] = j;
    }
    for (i = 0, x = -128; i < 256; i++, x++) {
        arr[indices[i]] = x; // Indirect access via index array
    }
}
