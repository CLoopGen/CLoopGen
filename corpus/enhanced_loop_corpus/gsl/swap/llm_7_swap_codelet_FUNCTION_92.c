#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern  size_t size2;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp[1024];
    for (i = 0; i < size1 && i < 1024; i++) {
        temp[i] = i * i; // Write to array element (no loop-carried dependency)
        for (j = i + 1; j < size2 && j < 1024; j++) {
            temp[j] = temp[i] + j; // Introduce RAW dependency: read `temp[i]` written in outer loop
        }
    }
}
