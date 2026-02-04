#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[8] = {10, 20, 30, 40, 50, 60, 70, 80};
    int indices[] = {0, 2, 4, 6}; // Indirect access via index array
    for (i = 0; i < 4; i++) {
        // Strided and indirect memory access: every second element via lookup
        int idx = indices[i];
        arr[idx] *= 2;
    }
}
