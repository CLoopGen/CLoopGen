#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[16];
    int indices[] = {15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
    for (; k < 16; ++k) {
        arr[indices[k]] = k; // Indirect access: use index mapping (reverse order)
    }
}
