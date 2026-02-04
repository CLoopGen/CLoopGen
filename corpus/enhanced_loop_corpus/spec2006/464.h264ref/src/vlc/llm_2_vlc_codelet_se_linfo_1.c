#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int nn;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[16] = {0}; // Local array to enable memory access pattern modification
    for (i = 0; i < 16 && nn != 0; i++) {
        arr[i] = nn;      // Consecutive forward access
        nn /= 2;
    }
}
