#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[16];
    int indices[] = {15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
    for (j = 0; j < 16; ++j) {
        arr[indices[j]] = j; // Indirect access: use index mapping to write in reverse order
    }
}
