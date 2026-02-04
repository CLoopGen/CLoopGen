#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[10] = {0};
    int indices[] = {1, 3, 5};
    for (i = 0; i <= 2; ++i) {
        arr[indices[i]] += i; // Indirect access via index array
    }
}
