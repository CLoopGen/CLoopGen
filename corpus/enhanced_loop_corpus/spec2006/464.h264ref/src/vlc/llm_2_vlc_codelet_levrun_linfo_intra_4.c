#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int nn;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[16] = {0}; // Local array to simulate memory access
    for (i = 0; i < 16 && nn != 0; i += 2) { // Strided access: step by 2
        arr[i] = nn;
        nn /= 2;
    }
}
