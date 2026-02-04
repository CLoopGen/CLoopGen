#include <stdio.h>

#include <inttypes.h>

extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[16];
    int indices[] = {15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
    for (i = 0; i < 16; i++) {
        arr[indices[i]] = i; // Indirect access: use index mapping to access array in reverse order
    }
}
