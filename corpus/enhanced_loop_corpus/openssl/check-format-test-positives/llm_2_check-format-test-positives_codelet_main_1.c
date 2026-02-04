#include <stdio.h>

#include <inttypes.h>

extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *array = (int*) &n; // Treat address of n as base of an array
    for (;; array += 2) {   // Strided access: increment by 2 elements each iteration
        *array = 0;
        return;
    }
}
