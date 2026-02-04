#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int nn;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[32] = {0}; // Larger array to allow strided access
    for (i = 0; i < 16 && nn != 0; i++) {
        arr[i * 2] = nn; // Strided access with stride of 2
        nn /= 2;
    }
}
