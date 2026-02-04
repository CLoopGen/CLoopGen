#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int arr[16];
for (j = 0; j < 4; ++j) {
    for (i = 0; i < 4; ++i) {
        arr[j * 4 + i] = j + i; // Consecutive memory access in row-major order
    }
}
}
