#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int planes;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int* buffer = (int*)malloc(planes * sizeof(int));
    if (!buffer) return;
    for (int i = 0; i < planes; i++) {
        buffer[i] = i * 2;
        if (i > 0) {
            buffer[i] += buffer[i-1]; // Introduce loop-carried read-after-write (RAW) dependency
        }
    }
    free(buffer);
}
