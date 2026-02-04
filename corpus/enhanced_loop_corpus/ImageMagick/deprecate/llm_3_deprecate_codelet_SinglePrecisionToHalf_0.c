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
    arr[indices[0]] = alpha;
    for (i = 1; i < 10; i++) {
        arr[indices[i]] = arr[indices[i-1]] * arr[indices[i-1]];
    }
    alpha = arr[indices[9]];
}
