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
        arr[i * 4 + j] = j + i; // Strided memory access (column-major traversal of a 4x4 grid)
    }
}
}
