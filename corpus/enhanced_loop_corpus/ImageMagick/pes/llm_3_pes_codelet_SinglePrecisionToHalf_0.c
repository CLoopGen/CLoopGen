#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float alpha;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float arr[20];
    int indices[10];
    for (i = 0; i < 10; i++) {
        indices[i] = 2 * i; // Strided index pattern
    }
    for (i = 0; i < 10; i++) {
        arr[indices[i]] = alpha * alpha;
        alpha = arr[indices[i]];
    }
}
